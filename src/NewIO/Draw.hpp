#pragma once
#include "../utils/Core.hpp"
#include "ascii-font/ascii-font.hpp"

#define W 128
#define H 64

ACCESS_PRIVATE_FIELD(OLED_I2C_SSD1309, int8_t, _i2caddr)
auto &i2caddr = access_private::_i2caddr(oled);
DMA_HandleTypeDef hdma_i2c1_tx;

static bool oled_dma_busy = false;

static uint8_t screen[1024];
static uint8_t txbuf[13 + 1024] = {
    0x80, SSD1309_COLUMNADDR, 
    0x80, 0, 
    0x80, SSD1309_LCDWIDTH - 1,

    0x80, SSD1309_PAGEADDR, 
    0x80, 0, 
    0x80, (SSD1309_LCDHEIGHT/8) - 1,

    0x40
};

void OLED_DMA_Init() {
    I2C_HandleTypeDef *hi2c_oled = Wire.getHandle();
    
    __HAL_RCC_DMA1_CLK_ENABLE();
    
    hdma_i2c1_tx.Instance                 = DMA1_Channel6;
    hdma_i2c1_tx.Init.Direction           = DMA_MEMORY_TO_PERIPH;
    hdma_i2c1_tx.Init.PeriphInc           = DMA_PINC_DISABLE;
    hdma_i2c1_tx.Init.MemInc              = DMA_MINC_ENABLE; 
    hdma_i2c1_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_i2c1_tx.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
    hdma_i2c1_tx.Init.Mode                = DMA_NORMAL;
    hdma_i2c1_tx.Init.Priority            = DMA_PRIORITY_HIGH;
    
    HAL_DMA_Init(&hdma_i2c1_tx);
    
    __HAL_LINKDMA(hi2c_oled, hdmatx, hdma_i2c1_tx);
    
    HAL_NVIC_SetPriority(DMA1_Channel6_IRQn, 0, 0); 
    HAL_NVIC_EnableIRQ(DMA1_Channel6_IRQn);
}

extern "C" void DMA1_Channel6_IRQHandler(void) {
    HAL_DMA_IRQHandler(&hdma_i2c1_tx);
}

extern "C" void HAL_I2C_MasterTxCpltCallback(I2C_HandleTypeDef *hi2c) {
    if (hi2c == Wire.getHandle()) {
        oled_dma_busy = false;
    }
}

inline void flip() {
    if (oled_dma_busy) return;
    oled_dma_busy = true;

    I2C_HandleTypeDef *hi2c = Wire.getHandle(); 
    uint8_t i2c_addr_8bit = i2caddr << 1; 

    memcpy(&txbuf[13], screen, 1024);
    HAL_I2C_Master_Transmit_DMA(
        hi2c, 
        i2c_addr_8bit, 
        txbuf, 
        (13 + 1024)
    );
}

void clear() {
    memset(screen, 0, 1024);
}

inline void putPixel(int x, int y, uint8_t color) {
    if (x < 0 || y < 0 || x >= W || y >= H) return;

    uint16_t index = x + (y >> 3) * W;
    uint8_t bit = 1 << (y & 7);

    switch (color) {
        case WHITE:   screen[index] |=  bit; break;
        case BLACK:   screen[index] &= ~bit; break;
        case INVERSE: screen[index] ^=  bit; break;
    }
}

void drawRect(int x, int y, int w, int h, uint8_t color) {
    if (w <= 0 || h <= 0) return;

    int x2 = x + w;
    int y2 = y + h;

    if (x < 0) x = 0;
    if (y < 0) y = 0;
    if (x2 > W) x2 = W;
    if (y2 > H) y2 = H;

    int firstPage = y >> 3;
    int lastPage  = (y2 - 1) >> 3;

    for (int page = firstPage; page <= lastPage; page++) {

        uint8_t mask;

        if (page == firstPage && page == lastPage) {
            int topOffset = y & 7;
            int bottomOffset = (y2 - 1) & 7;
            mask = ((0xFF << topOffset) & (0xFF >> (7 - bottomOffset)));

        } else if (page == firstPage) {
            mask = 0xFF << (y & 7);

        } else if (page == lastPage) {
            mask = 0xFF >> (7 - ((y2 - 1) & 7));

        } else {
            mask = 0xFF;
        }

        int index = page * W + x;

        for (int xx = x; xx < x2; xx++) {
            switch (color) {
            case WHITE:   screen[index] |=  mask; break;
            case BLACK:   screen[index] &= ~mask; break;
            case INVERSE: screen[index] ^=  mask; break;
            }
            index++;
        }
    }
}

void drawLine(int x0, int y0, int x1, int y1, uint8_t color) {
    int dx = abs(x1-x0), sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1-y0), sy = y0 < y1 ? 1 : -1;
    int err = dx + dy, e2;

    for (;;) {
        putPixel(x0, y0, color);
        if (x0 == x1 && y0 == y1) break;
        e2 = err * 2;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
}

void drawChar(int x, int y, char c, uint8_t color) {
    if (c < 0x20 || c > 0x7E) return;

    const uint8_t* col = font5x7[c - 0x20];

    for (int i = 0; i < 5; i++) {
        uint8_t bits = col[i];
        for (int j = 0; j < 7; j++) {
            if (bits & (1 << j)) {
                putPixel(x + i, y + j, color);
            }
        }
    }
}

void drawText(int x, int y, const char* s, uint8_t color) {
    while (*s) {
        drawChar(x, y, *s++, color);
        x += 6;
    }
}

void drawTextFmt(int x, int y, uint8_t color, const char* fmt, ...) {
    char buffer[64];

    va_list args;
    va_start(args, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);

    drawText(x, y, buffer, color);
}

void getTextSizeFmt(int &outW, int &outH, const char* fmt, ...) {
    char buffer[64];

    va_list args;
    va_start(args, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);

    int len = strlen(buffer);

    if (len == 0) {
        outW = 0;
        outH = 0;
        return;
    }

    // width: each character is 5px + 1px spacing, except last one
    outW = len * 6 - 1;

    // height: font is 7px tall
    outH = 7;
}

void drawGrid(int spacing, int offsetX, int offsetY, uint8_t color) {
    for (int y = 0; y < H; y++) {
        int yWithOffset = (y + offsetY) % spacing;

        for (int x = 0; x < W; x++) {
            int xWithOffset = (x + offsetX) % spacing;

            bool draw = (xWithOffset == 0) || (yWithOffset == 0);
            if (!draw) continue;

            int index = x + (y / 8) * W;
            uint8_t mask = 1 << (y & 7);

            switch (color) {
                case WHITE:   screen[index] |=  mask; break;
                case BLACK:   screen[index] &= ~mask; break;
                case INVERSE: screen[index] ^=  mask; break;
            }
        }
    }
}

void drawChecker(int tileSize, int offsetX, int offsetY, uint8_t color1, uint8_t color2) {
    for (int y = 0; y < H; y++) {
        int ty = ((y + offsetY) / tileSize) & 1;   // row toggler

        for (int x = 0; x < W; x++) {
            int tx = ((x + offsetX) / tileSize) & 1; // col toggler

            bool isColor1 = (tx ^ ty) == 0;   // XOR determines square color
            uint8_t color = isColor1 ? color1 : color2;

            int index = x + (y / 8) * W;
            uint8_t mask = 1 << (y & 7);

            switch (color) {
                case WHITE:   screen[index] |=  mask; break;
                case BLACK:   screen[index] &= ~mask; break;
                case INVERSE: screen[index] ^=  mask; break;
            }
        }
    }
}
