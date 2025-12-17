#pragma once
#include "../FastOled/FastOled.hpp";

#include <vector>

template <typename T>
T lerp(T a, T b, T t) {return a + t * (b - a);}

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
