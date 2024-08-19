#include "Lys/core/math/vector3.hpp"
#include <gtest/gtest.h>

using namespace Lys;

// ADDITION TESTS

TEST(Vector3_Test, AddTriplePositive)
{
	Vector3 vector_a(2, 3, 5);
	Vector3 vector_b(3, 3, 10);
	ASSERT_EQ(vector_a + vector_b, Vector3(5, 6, 15));
}

TEST(Vector3_Test, AddNegativePositive)
{
	Vector3 vector_a(-6, 3, 18);
	Vector3 vector_b(3, -3, -8);
	ASSERT_EQ(vector_a + vector_b, Vector3(-3, 0, 10));
}

TEST(Vector3_Test, AddTripleNegative)
{
	Vector3 vector_a(-6, -13, -102);
	Vector3 vector_b(-21, -3, -11);
	ASSERT_EQ(vector_a + vector_b, Vector3(-27, -16, -113));
}

// SUBTRACTION TESTS

TEST(Vector3_Test, SubtractTriplePositive)
{
	Vector3 vector_a(2, 3, 10);
	Vector3 vector_b(3, 3, 13);
	ASSERT_EQ(vector_a - vector_b, Vector3(-1, 0, -3));
}

TEST(Vector3_Test, SubtractNegativePositive)
{
	Vector3 vector_a(-6, 3, -45);
	Vector3 vector_b(3, -3, 23);
	ASSERT_EQ(vector_a - vector_b, Vector3(-9, 6, -68));
}

TEST(Vector3_Test, SubtractTripleNegative)
{
	Vector3 vector_a(-6, -13, -1);
	Vector3 vector_b(-21, -3, -12);
	ASSERT_EQ(vector_a - vector_b, Vector3(15, -10, 11));
}

// MULTIPLICATION TESTS

TEST(Vector3_Test, MultiplyTriplePositive)
{
	Vector3 vector_a(2, 3, 4);
	Vector3 vector_b(3, 3, 8);
	ASSERT_EQ(vector_a * vector_b, Vector3(6, 9, 32));
}

TEST(Vector3_Test, MultiplyNegativePositive)
{
	Vector3 vector_a(-6, 3, -4);
	Vector3 vector_b(3, -3, 2);
	ASSERT_EQ(vector_a * vector_b, Vector3(-18, -9, -8));
}

TEST(Vector3_Test, MultiplyTripleNegative)
{
	Vector3 vector_a(-6, -13, -10);
	Vector3 vector_b(-21, -3, -2);
	ASSERT_EQ(vector_a * vector_b, Vector3(126, 39, 20));
}

// DIVISION TESTS

TEST(Vector3_Test, DivideTriplePositive)
{
	Vector3 vector_a(2, 3, 16);
	Vector3 vector_b(3, 3, 4);
	ASSERT_EQ(vector_a / vector_b, Vector3(0.666666667, 1.0, 4.0));
}

TEST(Vector3_Test, DivideNegativePositive)
{
	Vector3 vector_a(-6, 3, -10);
	Vector3 vector_b(3, -3, 20);
	ASSERT_EQ(vector_a / vector_b, Vector3(-2.0, -1.0, -0.5));
}

TEST(Vector3_Test, DivideTripleNegative)
{
	Vector3 vector_a(-6, -13, -3);
	Vector3 vector_b(-21, -3, -6);
	ASSERT_EQ(vector_a / vector_b, Vector3(0.285714286, 4.333333333, 0.5));
}