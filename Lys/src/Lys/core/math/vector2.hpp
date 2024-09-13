#pragma once

#include "Lys/core/utils/typedef.hpp"

namespace Lys
{
	struct Vector2
	{
		fp_type x;
		fp_type y;

		Vector2() = default;

		Vector2(const fp_type x, const fp_type y) : x(x), y(y) {}

		Vector2 clamp(fp_type min_x, fp_type max_x, fp_type min_y, fp_type max_y);

		Vector2 clamp(const Vector2 &min, const Vector2 &max);

		static fp_type dot_product(const Vector2 &p_vec1, const Vector2 &p_vec2);
		static fp_type dot_product(const Vector2 &p_vec1, const Vector2 &p_vec2, const fp_type &theta);

		[[nodiscard]] Vector2 normalized() const;

		[[nodiscard]] bool is_normalized() const;

		[[nodiscard]] fp_type magnitude() const;

		[[nodiscard]] fp_type magnitude_squared() const;

		_FORCE_INLINE_ Vector2 operator+(const fp_type scalar) const { return {x + scalar, y + scalar}; }

		_FORCE_INLINE_ Vector2 operator-(const fp_type scalar) const { return {x - scalar, y - scalar}; }

		_FORCE_INLINE_ Vector2 operator*(const fp_type scalar) const { return {x * scalar, y * scalar}; }

		_FORCE_INLINE_ Vector2 operator/(const fp_type scalar) const { return {x / scalar, y / scalar}; }

		_FORCE_INLINE_ Vector2 operator+(const Vector2 &other) const { return {x + other.x, y + other.y}; }

		_FORCE_INLINE_ Vector2 operator-(const Vector2 &other) const { return {x - other.x, y - other.y}; }

		_FORCE_INLINE_ Vector2 operator*(const Vector2 &other) const { return {x * other.x, y * other.y}; }

		_FORCE_INLINE_ Vector2 operator/(const Vector2 &other) const { return {x / other.x, y / other.y}; }

		_FORCE_INLINE_ void operator+=(const Vector2 &other)
		{
			x += other.x;
			y += other.y;
		}

		_FORCE_INLINE_ void operator-=(const Vector2 &other)
		{
			x -= other.x;
			y -= other.y;
		}

		_FORCE_INLINE_ void operator*=(const Vector2 &other)
		{
			x *= other.x;
			y *= other.y;
		}

		_FORCE_INLINE_ void operator/=(const Vector2 &other)
		{
			x /= other.x;
			y /= other.y;
		}

		_FORCE_INLINE_ bool operator<=>(const Vector2 &other) const = default;
	};
	typedef Vector2 Point2;
} // namespace Lys