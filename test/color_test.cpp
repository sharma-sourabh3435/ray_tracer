#include "pch.h"
#include "../src/include/color.hpp"
#include "../src/features/color.cpp"

const double EPSILON = 1e-5;
TEST(color, color_constructor)
{
	color c(-0.5, 0.4, 1.7);
	EXPECT_NEAR(-0.5, c.red, EPSILON);
	EXPECT_NEAR(0.4, c.green, EPSILON);
	EXPECT_NEAR(1.7, c.blue, EPSILON);
}

TEST(color, color_add)
{
	color c1(0.9, 0.6, 0.75);
	color c2(0.7, 0.1, 0.25);
	color res = add(c1, c2);
	EXPECT_NEAR(res.red, 1.6, EPSILON);
	EXPECT_NEAR(res.green, 0.7, EPSILON);
	EXPECT_NEAR(res.blue, 1.0, EPSILON);
}

TEST(color, color_sub)
{
	color c1(0.9, 0.6, 0.75);
	color c2(0.7, 0.1, 0.25);
	color res = sub(c1, c2);
	EXPECT_NEAR(res.red, 0.2, EPSILON);
	EXPECT_NEAR(res.green, 0.5, EPSILON);
	EXPECT_NEAR(res.blue, 0.5, EPSILON);
}

TEST(color, color_scalar)
{
	color c(0.2, 0.3, 0.4);
	color res = scalar_mult(c, 2);
	EXPECT_NEAR(res.red, 0.4, EPSILON);
	EXPECT_NEAR(res.green, 0.6, EPSILON);
	EXPECT_NEAR(res.blue, 0.8, EPSILON);
}

TEST(color, color_mult)
{
	color c1(1.0, 0.2, 0.4);
	color c2(0.9, 1.0, 0.1);
	color res = mult(c1, c2);
	EXPECT_NEAR(res.red, 0.9, EPSILON);
	EXPECT_NEAR(res.green, 0.2, EPSILON);
	EXPECT_NEAR(res.blue, 0.04, EPSILON);
}
