#pragma once
#include "ascii-font/ascii-font.hpp"
#include "../utils/Core.hpp"
#define OLED_W 128
#define OLED_H 64

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

class FAST_OLED{
    public:
    void OLED_DMA_Init();
    inline void show();
    void clear();
    inline void put(int x, int y, uint8_t color);
    void drawRect(int x, int y, int w, int h, uint8_t color);
    void drawLine(int x0, int y0, int x1, int y1, uint8_t color);
    void drawChar(int x, int y, char c, uint8_t color);
    void text(int x, int y, uint8_t color, const char* s);
    void textf(int x, int y, uint8_t color, const char* fmt, ...);
    void getTextSizef(int &outW, int &outH, const char* fmt, ...);
    void drawGrid(int spacing, int offsetX, int offsetY, uint8_t color);
    void drawChecker(int tileSize, int offsetX, int offsetY, uint8_t color1, uint8_t color2);
};

extern "C" void DMA1_Channel6_IRQHandler(void);
extern "C" void HAL_I2C_MasterTxCpltCallback(I2C_HandleTypeDef *hi2c);