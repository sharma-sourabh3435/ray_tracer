#include "pch.h"
#include "../src/include/tuple.hpp"

TEST(tuple_test, default_contructor)
{
	tuple t;
	EXPECT_DOUBLE_EQ(t.x, 0.0);
	EXPECT_DOUBLE_EQ(t.y, 0.0);
	EXPECT_DOUBLE_EQ(t.z, 0.0);
	EXPECT_DOUBLE_EQ(t.w, 0.0);
}

TEST(tuple_test, param_constructor)
{
	tuple t(1.0, 2.0, 3.0, 4.0);
	EXPECT_DOUBLE_EQ(t.x, 1.0);
	EXPECT_DOUBLE_EQ(t.y, 2.0);
	EXPECT_DOUBLE_EQ(t.z, 3.0);
	EXPECT_DOUBLE_EQ(t.w, 4.0);
}

TEST(point_test, constructor_p)
{
	point p(2.0, 3.0, 4.0);
	EXPECT_DOUBLE_EQ(p.point_tuple.x, 2.0);
	EXPECT_DOUBLE_EQ(p.point_tuple.y, 3.0);
	EXPECT_DOUBLE_EQ(p.point_tuple.z, 4.0);
	EXPECT_DOUBLE_EQ(p.point_tuple.w, 1.0);
}

TEST(vector_test, constructor_v)
{
	vector v(2.0, 3.0, 4.0);
	EXPECT_DOUBLE_EQ(v.vector_tuple.x, 2.0);
	EXPECT_DOUBLE_EQ(v.vector_tuple.y, 3.0);
	EXPECT_DOUBLE_EQ(v.vector_tuple.z, 4.0);
	EXPECT_DOUBLE_EQ(v.vector_tuple.w, 0.0);
}
