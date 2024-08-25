#ifndef TUPLE_HPP
#define TUPLE_HPP

// tuple initiates to (0,0,0,0)
struct tuple {
    double x;
    double y;
    double z;
    double w;

    tuple(double x_val = 0, double y_val = 0, double z_val = 0, double w_val = 0)
        : x(x_val), y(y_val), z(z_val), w(w_val) {}
};

// for the point object
class point {
public:
    tuple point_tuple;
    point(double x, double y, double z) : point_tuple(x, y, z, 1.0) {}
};

//for the vector object
class vector {
public:
    tuple vector_tuple;
    vector(double x, double y, double z) : vector_tuple(x, y, z, 0.0) {}
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


//compare two doubles
bool equal(const double& a, const double& b);
tuple add(const tuple& a, const tuple& b);
tuple sub(const tuple& a, const tuple& b);
tuple negate(const tuple& a);
tuple scalar_mult(const tuple& a, const double& num);
tuple scalar_div(const tuple& a, const double& num);
double magnitude(const tuple& a);
tuple normalize(const tuple& a);
double dot(const tuple& a, const tuple& b);
tuple cross(const tuple& a, const tuple& b);

bool is_vector(const tuple& a);
bool is_point(const tuple& b);

projectile tick(const environment& env, const projectile& proj);

#endif // TUPLE_HPP