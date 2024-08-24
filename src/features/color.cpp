#include "../include/color.hpp"

color add(const color& a, const color& b) {
    return color(a.red + b.red, a.green + b.green, a.blue + b.blue);
}

color sub(const color& a, const color& b) {
    return color(a.red - b.red, a.green - b.green, a.blue - b.blue);
}

color scalar_mult(const color& a, const double& num) {
    return color(a.red * num, a.green * num, a.blue * num);
}

color mult(const color& a, const color& b) {
    return color(a.red * b.red, a.green * b.green, a.blue * b.blue);
}