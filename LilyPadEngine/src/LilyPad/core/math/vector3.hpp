#pragma once

#include <glm/glm.hpp>
#include "LilyPad/core/utils/typedef.hpp"

namespace LilyPad
{
	struct Vector3
	{
		fp_type x;
		fp_type y;
		fp_type z;

		Vector3() = default;

		Vector3(fp_type x, fp_type y, fp_type z);

		Vector3 cross(const Vector3 &other) const;
		static Vector3 cross(const Vector3 &vector_a, const Vector3 &vector_b);
		static Vector3 normalize(const Vector3 &vector);

		fp_type dot(const Vector3 &other) const;

		_FORCE_INLINE_ Vector3 operator+(const fp_type scalar) const { return {x + scalar, y + scalar, z + scalar}; }

		_FORCE_INLINE_ Vector3 operator-(const fp_type scalar) const { return {x - scalar, y - scalar, z - scalar}; }

		_FORCE_INLINE_ Vector3 operator*(const fp_type scalar) const { return {x * scalar, y * scalar, z * scalar}; }

		_FORCE_INLINE_ Vector3 operator/(const fp_type scalar) const { return {x / scalar, y / scalar, z / scalar}; }

		_FORCE_INLINE_ Vector3 operator+=(const fp_type scalar) const
		{
			return Vector3(x + scalar, y + scalar, z + scalar);
		}

		_FORCE_INLINE_ Vector3 operator+(const Vector3 &other) const { return {x + other.x, y + other.y, z + other.z}; }

		_FORCE_INLINE_ Vector3 operator-(const Vector3 &other) const { return {x - other.x, y - other.y, z - other.z}; }

		_FORCE_INLINE_ Vector3 operator*(const Vector3 &other) const { return {x * other.x, y * other.y, z * other.z}; }

		_FORCE_INLINE_ Vector3 operator/(const Vector3 &other) const { return {x / other.x, y / other.y, z / other.z}; }

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

		_FORCE_INLINE_ operator glm::vec3() { return glm::vec3(x, y, z); }

		friend Vector3 operator*(float scalar, const Vector3 &vec)
		{
			return Vector3(vec.x * scalar, vec.y * scalar, vec.z * scalar);
		}

		Vector3 normalize() const;
	};

	typedef Vector3 Position3;
} // namespace LilyPad
