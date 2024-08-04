#ifndef COLOR_H
#define COLOR_H

#include "tuple.h"

struct color {
    float red;
    float green;
    float blue;
    color(float red_val = 0, float green_val = 0, float blue_val = 0)
        : red(red_val), green(green_val), blue(blue_val) {}
    bool operator==(const color& other) const {
        return red == other.red && green == other.green && blue == other.blue;
    }
};

color add(const color& a, const color& b);
color sub(const color& a, const color& b);
color scalar_mult(const color& a, const float& num);
color mult(const color& a, const color& b);


#endif