#pragma once

#include "LilyPad/core/utils/typedef.hpp"

namespace LilyPad
{
	struct Vector3
	{
		fp_type x;
		fp_type y;
		fp_type z;

        Vector3() : x(0.0f), y(0.0f), z(0.0f) {}

		Vector3(fp_type x, fp_type y, fp_type z);

		_FORCE_INLINE_ Vector3 operator+(const fp_type scalar) const { return {x + scalar, y + scalar, z + scalar}; }

		_FORCE_INLINE_ Vector3 operator-(const fp_type scalar) const { return {x - scalar, y - scalar, z - scalar}; }

		_FORCE_INLINE_ Vector3 operator*(const fp_type scalar) const { return {x * scalar, y * scalar, z * scalar}; }

		_FORCE_INLINE_ Vector3 operator/(const fp_type scalar) const { return {x / scalar, y / scalar, z / scalar}; }

		_FORCE_INLINE_ Vector3 operator+(const Vector3 &other) const
		{
			return {x + other.x, y + other.y, z + other.z};
		}

		_FORCE_INLINE_ Vector3 operator-(const Vector3 &other) const
		{
			return {x - other.x, y - other.y, z - other.z};
		}

		_FORCE_INLINE_ Vector3 operator*(const Vector3 &other) const
		{
			return {x * other.x, y * other.y, z * other.z};
		}

		_FORCE_INLINE_ Vector3 operator/(const Vector3 &other) const
		{
			return {x / other.x, y / other.y, z / other.z};
		}

		_FORCE_INLINE_ void operator+=(const Vector3 &other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
		}

		_FORCE_INLINE_ void operator-=(const Vector3 &other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
		}

		_FORCE_INLINE_ void operator*=(const Vector3 &other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;
		}

		_FORCE_INLINE_ void operator/=(const Vector3 &other)
		{
			x /= other.x;
			y /= other.y;
		}

		_FORCE_INLINE_ bool operator==(const Vector3 &other) const
		{
			return (x == other.x && y == other.y && z == other.z);
		}

		_FORCE_INLINE_ bool operator!=(const Vector3 &other) const
		{
			return (x != other.x && y != other.y && z != other.z);
		}

		_FORCE_INLINE_ bool operator>(const Vector3 &other) const { return x > other.x && y > other.y && z > other.z; }

		_FORCE_INLINE_ bool operator<(const Vector3 &other) const { return x < other.x && y < other.y && z < other.z; }

		_FORCE_INLINE_ bool operator>=(const Vector3 &other) const
		{
			return x >= other.x && y >= other.y && z >= other.z;
		};

		_FORCE_INLINE_ bool operator<=(const Vector3 &other) const
		{
			return x <= other.x && y <= other.y && z <= other.z;
		}
	};

} // namespace LilyPad
