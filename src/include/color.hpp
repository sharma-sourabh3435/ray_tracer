#ifndef COLOR_H
#define COLOR_H

#include "tuple.hpp"

struct color {
    double red;
    double green;
    double blue;
    color(double red_val = 0, double green_val = 0, double blue_val = 0)
        : red(red_val), green(green_val), blue(blue_val) {}
    bool operator==(const color& other) const {
        return red == other.red && green == other.green && blue == other.blue;
    }
};

color add(const color& a, const color& b);
color sub(const color& a, const color& b);
color scalar_mult(const color& a, const double& num);
color mult(const color& a, const color& b);


#endif