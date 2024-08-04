#ifndef TUPLE_H
#define TUPLE_H

// tuple initiates to (0,0,0,0)
struct tuple {
    float x;
    float y;
    float z;
    float w;

    tuple(float x_val = 0, float y_val = 0, float z_val = 0, float w_val = 0)
        : x(x_val), y(y_val), z(z_val), w(w_val) {}
};

// for the point object
class point {
public:
    tuple point_tuple;
    point(float x, float y, float z) : point_tuple(x, y, z, 1.0) {}
};

//for the vector object
class vector {
public:
    tuple vector_tuple;
    vector(float x, float y, float z) : vector_tuple(x, y, z, 0.0) {}
};

class projectile {
public:
    point position;
    vector velocity;
    projectile(const point& pos, const vector& vel) : position(pos), velocity(vel) {}
};

class environment {
public:
    vector gravity;
    vector wind;
    environment(const vector& grav, const vector& wnd) : gravity(grav), wind(wnd) {}
};


//compare two floats
bool equal(const float& a, const float& b);
tuple add(const tuple& a, const tuple& b);
tuple sub(const tuple& a, const tuple& b);
tuple negate(const tuple& a);
tuple scalar_mult(const tuple& a, const float& num);
tuple scalar_div(const tuple& a, const float& num);
float magnitude(const tuple& a);
tuple normalize(const tuple& a);
float dot(const tuple& a, const tuple& b);
tuple cross(const tuple& a, const tuple& b);

bool is_vector(const tuple& a);
bool is_point(const tuple& b);

projectile tick(const environment& env, const projectile& proj);

#endif