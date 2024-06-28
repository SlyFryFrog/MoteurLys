#include "LilyPad/core/math/vector2.hpp"
#include <gtest/gtest.h>

using namespace LilyPad;

TEST(Vector2_Test, AddDoublePositive)
{
	Vector2 vector_a(2, 3);
	Vector2 vector_b(3, 3);
	ASSERT_EQ(vector_a + vector_b, Vector2(5, 6));
}

TEST(Vector2_Test, AddNegativePositive)
{
	Vector2 vector_a(-6, 3);
	Vector2 vector_b(3, -3);
	ASSERT_EQ(vector_a + vector_b, Vector2(-3, 0));
}

TEST(Vector2_Test, AddDoubleNegative)
{
	Vector2 vector_a(-6, -13);
	Vector2 vector_b(-21, -3);
	ASSERT_EQ(vector_a + vector_b, Vector2(-27, -16));
}