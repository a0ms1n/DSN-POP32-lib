#include "Widget.h"
#include "../Timer/Timer.h"

void VerticalMenu::show(){
    int BUTTON_COUNT = buttons.size();

        float gridScroll = 0.0f;
        
        FlagTimer timer;
        timer.set();
        int target_offset_y = 0;
        float current_offset_y = 0.0f;

        Button last_button = {"", 0, (OLED_H - buttons[0].h) / 2, 0};
        for (int i = 0; i < BUTTON_COUNT; i++) {
            Button &button = buttons[i];
            button.y = last_button.y + last_button.h + last_button.margin;
            oledf.getTextSizef(button.w, button.h, button.label.c_str());
            last_button = button;
        }

        int selected = 0;
        while (SW_A());

        while (1) {
            float dt = timer.gap() / 1000.0f;
            gridScroll += dt * 60;
            int selected_button_center_y = buttons[selected].y + 
                                        (buttons[selected].h + buttons[selected].margin) / 2;        
            int center_target_y = OLED_H / 2;

            target_offset_y = center_target_y - selected_button_center_y;
            current_offset_y = lerp(current_offset_y, (float)target_offset_y, dt * 10.0f);

            selected = knob(BUTTON_COUNT-1);

            oledf.clear();
            oledf.drawChecker(8, (int) gridScroll, (int) gridScroll, WHITE, BLACK);

            int tw, th;
            oledf.getTextSizef(tw, th, "Select Option");
            oledf.drawRect(10, 4, tw+10, th+10, BLACK);
            oledf.textf(10+(10/2), 4+(10/2), INVERSE, "Select Option");
            
            for (int i = 0; i < BUTTON_COUNT; i++) { 
                Button &button = buttons[i];

                int draw_y = (int)(button.y + current_offset_y);
                int color = (i == selected) ? WHITE : BLACK;

                oledf.drawRect(button.x, draw_y, 
                        button.w + button.margin, button.h + button.margin, 
                        color);
                
                oledf.textf(button.x + (button.margin / 2), 
                            draw_y + (button.margin / 2), 
                            INVERSE, 
                            button.label.c_str());
            }

            oledf.show();
            if (SW_A()) {
                break;
            }
        }
        while (SW_A());
        buttons[selected].callback();
}