#include "pch.h"
#include "../src/include/tuple.hpp"
#include "../src/features/tuple.cpp"

const double EPSILON = 1e-5;
TEST(tuple_test, default_contructor)
{
	tuple t;
	EXPECT_NEAR(t.x, 0.0, EPSILON);
	EXPECT_NEAR(t.y, 0.0, EPSILON);
	EXPECT_NEAR(t.z, 0.0, EPSILON);
	EXPECT_NEAR(t.w, 0.0, EPSILON);
}

TEST(tuple_test, param_constructor)
{
	tuple t(1.0, 2.0, 3.0, 4.0);
	EXPECT_NEAR(t.x, 1.0, EPSILON);
	EXPECT_NEAR(t.y, 2.0, EPSILON);
	EXPECT_NEAR(t.z, 3.0, EPSILON);
	EXPECT_NEAR(t.w, 4.0, EPSILON);
}

TEST(point_test, constructor_p)
{
	point p(2.0, 3.0, 4.0);
	EXPECT_NEAR(p.point_tuple.x, 2.0, EPSILON);
	EXPECT_NEAR(p.point_tuple.y, 3.0, EPSILON);
	EXPECT_NEAR(p.point_tuple.z, 4.0, EPSILON);
	EXPECT_NEAR(p.point_tuple.w, 1.0, EPSILON);
}

TEST(vector_test, constructor_v)
{
	vector v(2.0, 3.0, 4.0);
	EXPECT_NEAR(v.vector_tuple.x, 2.0, EPSILON);
	EXPECT_NEAR(v.vector_tuple.y, 3.0, EPSILON);
	EXPECT_NEAR(v.vector_tuple.z, 4.0, EPSILON);
	EXPECT_NEAR(v.vector_tuple.w, 0.0, EPSILON);
}

TEST(projectile_test, constructor_p)
{
	point p(2.0, 3.0, 4.0);
	vector v(5.0, 6.0, 7.0);
	projectile pro(p, v);
	EXPECT_NEAR(pro.position.point_tuple.x, 2.0, EPSILON);
	EXPECT_NEAR(pro.position.point_tuple.y, 3.0, EPSILON);
	EXPECT_NEAR(pro.position.point_tuple.z, 4.0, EPSILON);
	EXPECT_NEAR(pro.velocity.vector_tuple.x, 5.0, EPSILON);
	EXPECT_NEAR(pro.velocity.vector_tuple.y, 6.0, EPSILON);
	EXPECT_NEAR(pro.velocity.vector_tuple.z, 7.0, EPSILON);
}

TEST(environment_test, constructor_e)
{
	vector g(2.0, 3.0, 4.0);
	vector w(5.0, 6.0, 7.0);
	environment env(g, w);
	EXPECT_NEAR(env.gravity.vector_tuple.x, 2.0, EPSILON);
	EXPECT_NEAR(env.gravity.vector_tuple.y, 3.0, EPSILON);
	EXPECT_NEAR(env.gravity.vector_tuple.z, 4.0, EPSILON);
	EXPECT_NEAR(env.wind.vector_tuple.x, 5.0, EPSILON);
	EXPECT_NEAR(env.wind.vector_tuple.y, 6.0, EPSILON);
	EXPECT_NEAR(env.wind.vector_tuple.z, 7.0, EPSILON);
}

TEST(tuple_test, add_tuple)
{
	tuple a1(3, -2, 5, 1);
	tuple a2(-2, 3, 1, 0);
	tuple res = add(a1, a2);
	EXPECT_NEAR(1, res.x, EPSILON);
	EXPECT_NEAR(1, res.y, EPSILON);
	EXPECT_NEAR(6, res.z, EPSILON);
	EXPECT_NEAR(1, res.w, EPSILON);
}

TEST(tuple_test, sub_point)
{
	point p1(3, 2, 1);
	point p2(5, 6, 7);
	tuple res = sub(p1.point_tuple, p2.point_tuple);
	EXPECT_NEAR(-2, res.x, EPSILON);
	EXPECT_NEAR(-4, res.y, EPSILON);
	EXPECT_NEAR(-6, res.z, EPSILON);
	EXPECT_NEAR(0, res.w, EPSILON);
}

TEST(tuple_test, sub_vector_from_point)
{
	point p(3, 2, 1);
	vector v(5, 6, 7);
	tuple res = sub(p.point_tuple, v.vector_tuple);
	EXPECT_NEAR(-2, res.x, EPSILON);
	EXPECT_NEAR(-4, res.y, EPSILON);
	EXPECT_NEAR(-6, res.z, EPSILON);
	EXPECT_NEAR(1, res.w, EPSILON);
}

TEST(tuple_test, sub_vector)
{
	vector v1(3, 2, 1);
	vector v2(5, 6, 7);
	tuple res = sub(v1.vector_tuple, v2.vector_tuple);
	EXPECT_NEAR(-2, res.x, EPSILON);
	EXPECT_NEAR(-4, res.y, EPSILON);
	EXPECT_NEAR(-6, res.z, EPSILON);
	EXPECT_NEAR(0, res.w, EPSILON);
}

TEST(tuple_test, negate_sub)
{
	vector v1(0, 0, 0);
	vector v2(1, -2, 3);
	tuple res = sub(v1.vector_tuple, v2.vector_tuple);
	EXPECT_NEAR(-1, res.x, EPSILON);
	EXPECT_NEAR(2, res.y, EPSILON);
	EXPECT_NEAR(-3, res.z, EPSILON);
}

TEST(tuple_test, negate)
{
	tuple t(1, -2, 3, -4);
	tuple res = negate(t);
	EXPECT_NEAR(-1, res.x, EPSILON);
	EXPECT_NEAR(2, res.y, EPSILON);
	EXPECT_NEAR(-3, res.z, EPSILON);
	EXPECT_NEAR(4, res.w, EPSILON);
}

TEST(tuple_test, scalar_mult)
{
	tuple t(1, -2, 3, -4);
	tuple res = scalar_mult(t, 3.5);
	EXPECT_NEAR(3.5, res.x, EPSILON);
	EXPECT_NEAR(-7, res.y, EPSILON);
	EXPECT_NEAR(10.5, res.z, EPSILON);
	EXPECT_NEAR(-14, res.w, EPSILON);
}

TEST(tuple_test, scalar_mult2)
{
	tuple t(1, -2, 3, -4);
	tuple res = scalar_mult(t, 0.5);
	EXPECT_NEAR(0.5, res.x, EPSILON);
	EXPECT_NEAR(-1, res.y, EPSILON);
	EXPECT_NEAR(1.5, res.z, EPSILON);
	EXPECT_NEAR(-2, res.w, EPSILON);
}

TEST(tuple_test, scalar_div)
{
	tuple t(1, -2, 3, -4);
	tuple res = scalar_div(t, 2);
	EXPECT_NEAR(0.5, res.x, EPSILON);
	EXPECT_NEAR(-1, res.y, EPSILON);
	EXPECT_NEAR(1.5, res.z, EPSILON);
	EXPECT_NEAR(-2, res.w, EPSILON);
}

TEST(tuple_test, mgnitde)
{
	vector v(1, 0, 0);
	double res = magnitude(v.vector_tuple);
	EXPECT_NEAR(res, 1, EPSILON);
}

TEST(tuple_test, mgnitde1)
{
	vector v(0, 1, 0);
	double res = magnitude(v.vector_tuple);
	EXPECT_NEAR(res, 1, EPSILON);
}

TEST(tuple_test, mgnitde2)
{
	vector v(0, 0, 1);
	double res = magnitude(v.vector_tuple);
	EXPECT_NEAR(res, 1, EPSILON);
}

TEST(tuple_test, mgnitde3)
{
	vector v(1, 2, 3);
	double res = magnitude(v.vector_tuple);
	EXPECT_NEAR(res, sqrt(14), EPSILON);
}

TEST(tuple_test, mgnitde4)
{
	vector v(-1, -2, -3);
	double res = magnitude(v.vector_tuple);
	EXPECT_NEAR(res, sqrt(14), EPSILON);
}

TEST(tuple_test, normalize)
{
	vector v(4, 0, 0);
	tuple res = normalize(v.vector_tuple);
	EXPECT_NEAR(1, res.x, EPSILON);
	EXPECT_NEAR(0, res.y, EPSILON);
	EXPECT_NEAR(1, res.x, EPSILON);
	EXPECT_NEAR(0, res.w, EPSILON);
}

TEST(tuple_test, normalize1)
{
	vector v(1, 2, 3);
	tuple res = normalize(v.vector_tuple);
	EXPECT_NEAR(0.26726, res.x, EPSILON);
	EXPECT_NEAR(0.53452, res.y, EPSILON);
	EXPECT_NEAR(0.80178, res.z, EPSILON);
	EXPECT_NEAR(0, res.w, EPSILON);
}

TEST(tuple_test, dot)
{
	vector v1(1, 2, 3);
	vector v2(2, 3, 4);
	double res = dot(v1.vector_tuple, v2.vector_tuple);
	EXPECT_NEAR(res, 20, EPSILON);
}

TEST(tuple_test, cross)
{
	vector v1(1, 2, 3);
	vector v2(2, 3, 4);
	tuple res = cross(v1.vector_tuple, v2.vector_tuple);
	tuple res1 = cross(v2.vector_tuple, v1.vector_tuple);
	EXPECT_NEAR(-1, res.x, EPSILON);
	EXPECT_NEAR(2, res.y, EPSILON);
	EXPECT_NEAR(-1, res.z, EPSILON);
	EXPECT_NEAR(1, res1.x, EPSILON);
	EXPECT_NEAR(-2, res1.y, EPSILON);
	EXPECT_NEAR(1, res1.z, EPSILON);
}