#include "LilyPad/core/math/vector2.hpp"
#include <gtest/gtest.h>

using namespace LilyPad;

// ADDITION TESTS

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

// SUBTRACTION TESTS

TEST(Vector2_Test, SubtractDoublePositive)
{
	Vector2 vector_a(2, 3);
	Vector2 vector_b(3, 3);
	ASSERT_EQ(vector_a - vector_b, Vector2(-1, 0));
}

TEST(Vector2_Test, SubtractNegativePositive)
{
	Vector2 vector_a(-6, 3);
	Vector2 vector_b(3, -3);
	ASSERT_EQ(vector_a - vector_b, Vector2(-9, 6));
}

TEST(Vector2_Test, SubtractDoubleNegative)
{
	Vector2 vector_a(-6, -13);
	Vector2 vector_b(-21, -3);
	ASSERT_EQ(vector_a - vector_b, Vector2(15, -10));
}

// MULTIPLICATION TESTS

TEST(Vector2_Test, MultiplyDoublePositive)
{
	Vector2 vector_a(2, 3);
	Vector2 vector_b(3, 3);
	ASSERT_EQ(vector_a * vector_b, Vector2(6, 9));
}

TEST(Vector2_Test, MultiplyNegativePositive)
{
	Vector2 vector_a(-6, 3);
	Vector2 vector_b(3, -3);
	ASSERT_EQ(vector_a * vector_b, Vector2(-18, -9));
}

TEST(Vector2_Test, MultiplyDoubleNegative)
{
	Vector2 vector_a(-6, -13);
	Vector2 vector_b(-21, -3);
	ASSERT_EQ(vector_a * vector_b, Vector2(126, 39));
}

// DIVISION TESTS

TEST(Vector2_Test, DivideDoublePositive)
{
	Vector2 vector_a(2, 3);
	Vector2 vector_b(3, 3);
	ASSERT_EQ(vector_a / vector_b, Vector2(0.666666667f, 1.0f));
}

TEST(Vector2_Test, DivideNegativePositive)
{
	Vector2 vector_a(-6, 3);
	Vector2 vector_b(3, -3);
	ASSERT_EQ(vector_a / vector_b, Vector2(-2.0f, -1.0f));
}

TEST(Vector2_Test, DivideDoubleNegative)
{
	Vector2 vector_a(-6, -13);
	Vector2 vector_b(-21, -3);
	ASSERT_EQ(vector_a / vector_b, Vector2(0.285714286f, 4.333333333f));
}