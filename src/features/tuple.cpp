#include "../include/tuple.hpp"
#include <cmath>


bool equal(const double& a, const double& b) {
    const double epsilon = 0.00001;
    if (std::fabs(a - b) < epsilon)
        return true;
    return false;
}

tuple add(const tuple& a, const tuple& b) {
    tuple result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    result.w = a.w + b.w;
    return result;
}

tuple sub(const tuple& a, const tuple& b) {
    tuple result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    result.w = a.w - b.w;
    return result;
}

tuple negate(const tuple& a) {
    tuple result;
    result.x = -a.x;
    result.y = -a.y;
    result.z = -a.y;
    result.w = -a.w;
    return result;
}

tuple scalar_mult(const tuple& a, const double& num) {
    tuple result;
    result.x = a.x * num;
    result.y = a.y * num;
    result.z = a.z * num;
    result.w = a.w * num;
    return result;
}

tuple scalar_div(const tuple& a, const double& num) {
    tuple result;
    result.x = a.x / num;
    result.y = a.y / num;
    result.z = a.z / num;
    result.w = a.w / num;
    return result;
}

double magnitude(const tuple& a) {
    double result = 0.0;
    result = sqrtf(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w);
    return result;
}

tuple normalize(const tuple& a) {
    double mgni = magnitude(a);
    tuple result;
    result.x = a.x / mgni;
    result.y = a.y / mgni;
    result.z = a.z / mgni;
    result.w = a.w / mgni;
    return result;
}

double dot(const tuple& a, const tuple& b) {
    double result = 0.0;
    result = a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
    return result;
}

tuple cross(const tuple& a, const tuple& b) {
    tuple result;
    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;
    result.w = 0.0;
    return result;
}

bool is_vector(const tuple& a) {
    if (a.w == 0.0)
        return true;
    return false;
}

bool is_point(const tuple& a) {
    if (a.w == 1.0)
        return true;
    return false;
}

projectile tick(const environment& env, const projectile& proj) {
    point new_position = point(
        proj.position.point_tuple.x + proj.velocity.vector_tuple.x,
        proj.position.point_tuple.y + proj.velocity.vector_tuple.y,
        proj.position.point_tuple.z + proj.velocity.vector_tuple.z
    );
    vector new_velocity = vector(
        proj.velocity.vector_tuple.x + env.gravity.vector_tuple.x + env.wind.vector_tuple.x,
        proj.velocity.vector_tuple.y + env.gravity.vector_tuple.y + env.wind.vector_tuple.y,
        proj.velocity.vector_tuple.z + env.gravity.vector_tuple.z + env.wind.vector_tuple.z
    );
    projectile my_projectile = projectile(new_position, new_velocity);
    return my_projectile;
}