#include "../include/canvas.h"

//write a pixel to the canvas
void canvas::write_pixel(float x, float y, const color& c) {
    if(x >= 0 && x < width && y >= 0 && y < height) {
        pixels[x][y] = c;
    }
}

//read a pixel from the canvas
color canvas::pixel_at(float x, float y) const {
    if(x >= 0 && x < width && y >= 0 && y < height) {
        return pixels[x][y];
    }
    return color(0,0,0); // return black if out of bounds
}

int clamp(float value) {
    return std::max(0, std::min(255, static_cast<int>(value * 255 + 0.5)));
}

//ppm header
std::string canvas_to_ppm(const canvas &c) {
    
    /*
    std::ostringstream ppm;

    // Write the PPM header
    ppm << "P3\n" << c.width << " " << c.height << "\n255\n";

    // Write the pixel data
    for (int y = 0; y < c.height; ++y) {
        std::ostringstream line;
        for (int x = 0; x < c.width; ++x) {
            const color &pixel = c.pixel_at(x, y);
            line << clamp(pixel.red) << " "
                << clamp(pixel.green) << " "
                << clamp(pixel.blue) << " ";
            
            // Ensure no line exceeds 70 characters
            if (line.str().length() > 65) {
                std::string line_str = line.str();
                size_t last_space = line_str.find_last_of(' ');
                ppm << line_str.substr(0, last_space) << "\n";
                line.str("");
                line.clear();
                line << line_str.substr(last_space + 1) << " ";
            }
        }
        std::string line_str = line.str();
        if (!line_str.empty()) {
            line_str.pop_back(); // Remove the trailing space
            ppm << line_str << "\n";
        }
    }

    return ppm.str();
    */
}

