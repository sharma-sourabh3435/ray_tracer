#ifndef CANVAS_H
#define CANVAS_H

#include "color.hpp"
#include "tuple.hpp"
#include <vector>
#include <string>
#include <sstream>

class canvas {
public:
    double width;
    double height;
    std::vector<std::vector<color>> pixels;

    canvas(double w, double h) : width(w), height(h), pixels(w, std::vector<color>(h, color(0.0, 0.0, 0.0))) {}

    void write_pixel(double x, double y, const color& c);
    color pixel_at(double x, double y) const;
};

std::string canvas_to_ppm(const canvas& c);

#endif

