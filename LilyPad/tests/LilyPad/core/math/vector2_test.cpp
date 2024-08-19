#include "LilyPad/core/math/vector2.hpp"
#include <gtest/gtest.h>
#include <math.h>
#include "LilyPad/core/utils/typedef.hpp"

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
	ASSERT_EQ(vector_a / vector_b, Vector2(0.666666667, 1.0));
}

TEST(Vector2_Test, DivideNegativePositive)
{
	Vector2 vector_a(-6, 3);
	Vector2 vector_b(3, -3);
	ASSERT_EQ(vector_a / vector_b, Vector2(-2.0, -1.0));
}

TEST(Vector2_Test, DivideDoubleNegative)
{
	Vector2 vector_a(-6, -13);
	Vector2 vector_b(-21, -3);
	ASSERT_EQ(vector_a / vector_b, Vector2(0.285714286, 4.333333333));
}

TEST(Vector2_Test, NormalizeVector)
{
	Vector2 vector_a(1, 1);

	ASSERT_EQ(vector_a.normalized(), Vector2(1 / std::sqrt(1 + 1), 1 / std::sqrt(1 + 1)));
	
	vector_a = Vector2(10, 15);

	ASSERT_EQ(vector_a.normalized(), Vector2(10 / std::sqrt(10 * 10 + 15 * 15), 15 / std::sqrt(10 * 10 + 15 * 15)));

	vector_a = Vector2(0, 1);

	ASSERT_EQ(vector_a.normalized(), Vector2(0 / std::sqrt(0 + 1), 1 / std::sqrt(0 + 1)));

	vector_a = Vector2(0, 0);

	ASSERT_EQ(vector_a.normalized(), Vector2(0, 0));
}