#pragma once
#include "../FastOled/FastOled.hpp";
#include "../utils/FastOperation.hpp"
#include <vector>

struct Button {
    String label;
    void (*callback)();
    int x;
    int y;
    int margin = 10;
    int w = 0;
    int h = 0;
};

/// @brief Class for storing menu in vertical alignment.
class VerticalMenu{
    public:
    std::vector<Button> buttons;

    VerticalMenu(const std::vector<Button> &x):buttons(x){}

    /// @brief Show menu
    /// @warning This will blocking other function.
    void show();
};

class SimpleVerticalMenu{
    public:
    std::vector<Button> buttons;
    SimpleVerticalMenu(const std::vector<Button> &x):buttons(x){}

    void show();
};
