#ifndef CANVAS_H
#define CANVAS_H

#include "color.h"
#include "tuple.h"
#include <vector>
#include <string>
#include <sstream>

class canvas {
public:
    float width;
    float height;
    std::vector<std::vector<color>> pixels;

    canvas(float w, float h) : width(w), height(h), pixels(w, 
    std::vector<color>(h, color(0,0,0))) {}

    void write_pixel(float x, float y, const color& c);
    color pixel_at(float x, float y) const;
};

std::string canvas_to_ppm(const canvas& c);

#endif

