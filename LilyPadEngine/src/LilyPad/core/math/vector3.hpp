#pragma once

#include "LilyPad/core/utils/typedef.hpp"

namespace LilyPad
{
	struct Vector3
	{
		float x;
		float y;
		float z;

		Vector3(float x, float y, float z);

		_FORCE_INLINE_ Vector3 operator+(float scalar) const { return Vector3(x + scalar, y + scalar, z + scalar); }

		_FORCE_INLINE_ Vector3 operator-(float scalar) const { return Vector3(x - scalar, y - scalar, z - scalar); }

		_FORCE_INLINE_ Vector3 operator*(float scalar) const { return Vector3(x * scalar, y * scalar, z * scalar); }

		_FORCE_INLINE_ Vector3 operator/(float scalar) const { return Vector3(x / scalar, y / scalar, z / scalar); }

		_FORCE_INLINE_ Vector3 operator+(const Vector3 &other) const
		{
			return Vector3(x + other.x, y + other.y, z + other.z);
		}

		_FORCE_INLINE_ Vector3 operator-(const Vector3 &other)
		{
			return Vector3(x - other.x, y - other.y, z - other.z);
		}

		_FORCE_INLINE_ Vector3 operator*(const Vector3 &other)
		{
			return Vector3(x * other.x, y * other.y, z * other.z);
		}

		_FORCE_INLINE_ Vector3 operator/(const Vector3 &other)
		{
			return Vector3(x / other.x, y / other.y, z / other.z);
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
