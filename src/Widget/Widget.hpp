#pragma once
#include "Widget.h"
#include "../Timer/Timer.h"

void VerticalMenu::show(){
    int BUTTON_COUNT = buttons.size();

    double_t gridScroll = 0.0f;

    FlagTimer Timer;
    
    
    int target_offset_y = 0;
    double_t current_offset_y = 0.0f;

    Button last_button = {"", 0, (OLED_H - buttons[0].h) / 2, 0};
    for (int i = 0; i < BUTTON_COUNT; i++) {
        Button &button = buttons[i];
        button.y = last_button.y + last_button.h + last_button.margin;
        oledf.getTextSizef(button.w, button.h, button.label.c_str());
        last_button = button;
    }

    int selected = 0;
    while (SW_A());

    Timer.set();
    while (1) {
        double_t dt = Timer.gap(true) / 1000.0f;

        gridScroll += dt * 60;
        
        int selected_button_center_y = buttons[selected].y + 
                                    (buttons[selected].h + buttons[selected].margin) / 2;        
        int center_target_y = OLED_H / 2;

        target_offset_y = center_target_y - selected_button_center_y;
        current_offset_y = lerp(current_offset_y, (double_t)target_offset_y, dt * 10.0f);

        selected = knob(BUTTON_COUNT-1);

        oledf.clear();

        oledf.drawChecker(8, (int) gridScroll, (int) gridScroll, WHITE, BLACK);

        int tw, th;
        oledf.getTextSizef(tw, th, "Select Option");
        oledf.drawRect(10, 4, tw+10, th+10, BLACK);
        oledf.text(10+(10/2), 4+(10/2), INVERSE, "Select Option");
        
        for (int i = 0; i < BUTTON_COUNT; i++) { 
            Button &button = buttons[i];

            int draw_y = (int)(button.y + current_offset_y);
            int color = (i == selected) ? WHITE : BLACK;

            oledf.drawRect(button.x, draw_y, 
                    button.w + button.margin, button.h + button.margin, 
                    color);
            
            oledf.text(button.x + (button.margin / 2), 
                        draw_y + (button.margin / 2), 
                        INVERSE, 
                        button.label.c_str());
        }

        // fps = lerp(fps, dt, dt * 10);
        // int fw, fh;
        // getTextSizeFmt(fw, fh, "FPS: %f", 1000.0f / (fps * 1000.0f));
        // drawRect(0, 0, fw, fh, BLACK);
        // drawTextFmt(0, 0, INVERSE, "FPS: %f", 1000.0f / (fps * 1000.0f));
        oledf.show();
        if (SW_A()) {
            break;
        }
    }
    while (SW_A());
    oledf.clear();
    oledf.show();
    buttons[selected].callback();
}

void SimpleVerticalMenu::show(){
    int BUTTON_COUNT = buttons.size();
    int8_t cur = 0;
    while(SW_A()){
        cur = knob(BUTTON_COUNT-1);
        for(int idx = max(0,cur-2);idx<=min(BUTTON_COUNT-1,cur+2);idx++){

        }
        if(SW_A())break;
    }
    while(SW_A());
    oledf.clear();
    oledf.show();
    buttons[cur].callback();
}