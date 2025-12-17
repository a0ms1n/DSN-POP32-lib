#pragma once
#include <draw/draw.hpp>

struct Menu {
    std::vector<Button> buttons;

    void menu() {
        int BUTTON_COUNT = buttons.size();

        float gridScroll = 0.0f;

        uint32_t lastTime = millis();
        // float fps = 0.0f;
        
        int target_offset_y = 0;
        float current_offset_y = 0.0f;

        Button last_button = {"", 0, (H - buttons[0].h) / 2, 0};
        for (int i = 0; i < BUTTON_COUNT; i++) {
            Button &button = buttons[i];
            button.y = last_button.y + last_button.h + last_button.margin;
            getTextSizeFmt(button.w, button.h, button.label.c_str());
            last_button = button;
        }

        int selected = 0;
        while (SW_A());

        while (1) {
            uint32_t now = millis();
            float dt = (now - lastTime) / 1000.0f;

            gridScroll += dt * 60;
            
            int selected_button_center_y = buttons[selected].y + 
                                        (buttons[selected].h + buttons[selected].margin) / 2;        
            int center_target_y = H / 2;

            target_offset_y = center_target_y - selected_button_center_y;
            current_offset_y = lerp(current_offset_y, (float)target_offset_y, dt * 10.0f);

            selected = knob(BUTTON_COUNT-1);

            clear();

            drawChecker(8, (int) gridScroll, (int) gridScroll, WHITE, BLACK);

            int tw, th;
            getTextSizeFmt(tw, th, "Select Option");
            drawRect(10, 4, tw+10, th+10, BLACK);
            drawTextFmt(10+(10/2), 4+(10/2), INVERSE, "Select Option");
            
            for (int i = 0; i < BUTTON_COUNT; i++) { 
                Button &button = buttons[i];

                int draw_y = (int)(button.y + current_offset_y);
                int color = (i == selected) ? WHITE : BLACK;

                drawRect(button.x, draw_y, 
                        button.w + button.margin, button.h + button.margin, 
                        color);
                
                drawTextFmt(button.x + (button.margin / 2), 
                            draw_y + (button.margin / 2), 
                            INVERSE, 
                            button.label.c_str());
            }

            // fps = lerp(fps, dt, dt * 10);
            // int fw, fh;
            // getTextSizeFmt(fw, fh, "FPS: %f", 1000.0f / (fps * 1000.0f));
            // drawRect(0, 0, fw, fh, BLACK);
            // drawTextFmt(0, 0, INVERSE, "FPS: %f", 1000.0f / (fps * 1000.0f));

            flip();

            lastTime = now;

            if (SW_A()) {
                break;
            }
        }
        while (SW_A());
        buttons[selected].callback();
    }
};