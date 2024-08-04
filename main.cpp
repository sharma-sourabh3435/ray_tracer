#include <iostream>
#include "../include/canvas.h"

int main() {
    //basic test
    /*
    tuple my_tuple = tuple(3.0, 4.0, 5.0, 1.0);
    std::cout << "tuple is " << my_tuple.x << " " << my_tuple.y 
    << " " << my_tuple.z << " " << my_tuple.w << std::endl;

    point my_point = point(2.1, 3.1, 1.2);
    std::cout << "point is " << my_point.point_tuple.x << " " << my_point.point_tuple.y
    << " " << my_point.point_tuple.z << " " << my_point.point_tuple.w << std::endl;

    vector my_vector = vector(3.1, 4.1, 5.1);
    std::cout << "vector is " << my_vector.vector_tuple.x << " " << my_vector.vector_tuple.y
    << " " << my_vector.vector_tuple.z << " " << my_vector.vector_tuple.w << std::endl;
    */

    //chapter 1 end test
    /*
    point start(0, 1, 0);
    tuple normalized = normalize(vector(1, 1, 0).vector_tuple);
    vector velo = vector(normalized.x, normalized.y, normalized.z);
    projectile p(start, velo);

    environment e(vector(0, -0.1, 0), vector(-0.01, 0, 0));
    int tick_count = 0;

    while (p.position.point_tuple.y > 0) {
        std::cout << "Tick : " << tick_count << " : ("
        << p.position.point_tuple.x << ", "
        << p.position.point_tuple.y << ", "
        << p.position.point_tuple.z << ")\n";
        p = tick(e, p);
        tick_count++;
    }

    std::cout << "The projectile hit the ground after " << tick_count << " ticks\n";
    */

    //canvas creation test
    /*
    canvas c(10, 20);
    if (c.width == 10 && c.height == 20)
        std::cout << "Canvas created\n";
    else
        std::cout << "Canvas creation failed\n";
    
    bool all_black = true;
    for (int x = 0; x < c.width; x++) {
        for (int y = 0; y < c.height; y++) {
            if(!(c.pixel_at(x, y) == color(0,0,0))) {
                all_black = false;
                break;
            }
        }
    }

    if (all_black) {
        std::cout << "canvas ititialized\n";
    }
    else {
        std::cout << "canvas not initialized\n";
    }

    color red(1, 0, 0);
    c.write_pixel(2, 3, red);
    if (c.pixel_at(2, 3) == red) {
        std::cout << "Pixel wrote\n";
    }
    else {
        std::cout << "Pixel not wrote\n";
    }
    */

    canvas c(5, 3);
    color c1(1.5, 0, 0);
    color c2(0, 0.5, 0);
    color c3(-0.5, 0, 1);

    c.write_pixel(0, 0, c1);
    c.write_pixel(2, 1, c2);
    c.write_pixel(4, 2, c3);

    std::string ppm = canvas_to_ppm(c);

    std::string expected = 
        "P3\n5 3\n255\n"
        "255 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n"
        "0 0 0 0 0 0 128 0 0 0 0 0 0 0 0\n"
        "0 0 0 0 0 0 0 0 0 0 0 0 0 0 255\n";
    
    if (ppm == expected) {
        std::cout << "PPM pixel data test passed\n";
    }
    else {
        std::cout << "something is wrong with ppm formatting\n";
        std::cout << "Expected: \n" << expected << "\n";
        std::cout << "Got: \n" << ppm << "\n";
    }

    return 0;
}

