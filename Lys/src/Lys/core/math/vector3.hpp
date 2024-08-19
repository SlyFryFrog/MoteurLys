#pragma once

#include <glm/glm.hpp>
#include "Lys/core/utils/typedef.hpp"

namespace Lys
{
	struct Vector3
	{
		fp_type x;
		fp_type y;
		fp_type z;

		Vector3() = default;

		Vector3(fp_type x, fp_type y, fp_type z);

		[[nodiscard]] Vector3 cross(const Vector3 &other) const;
		static Vector3 cross(const Vector3 &vector_a, const Vector3 &vector_b);

		[[nodiscard]] fp_type dot(const Vector3 &other) const;

		_FORCE_INLINE_ Vector3 operator+(const fp_type scalar) const { return {x + scalar, y + scalar, z + scalar}; }

		_FORCE_INLINE_ Vector3 operator-(const fp_type scalar) const { return {x - scalar, y - scalar, z - scalar}; }

		_FORCE_INLINE_ Vector3 operator*(const fp_type scalar) const { return {x * scalar, y * scalar, z * scalar}; }

		_FORCE_INLINE_ Vector3 operator/(const fp_type scalar) const { return {x / scalar, y / scalar, z / scalar}; }

		_FORCE_INLINE_ Vector3 operator+=(const fp_type scalar) const
		{
			return {x + scalar, y + scalar, z + scalar};
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

		_FORCE_INLINE_ bool operator<=>(const Vector3 &other) const = default;

		_FORCE_INLINE_ explicit operator glm::vec3() const { return {x, y, z}; }

		friend Vector3 operator*(const float scalar, const Vector3 &vec)
		{
			return {vec.x * scalar, vec.y * scalar, vec.z * scalar};
		}

		[[nodiscard]] Vector3 normalize() const;
		[[nodiscard]] static Vector3 normalize(const Vector3 &p_vector);
	};

	typedef Vector3 Position3;
} // namespace Lys
