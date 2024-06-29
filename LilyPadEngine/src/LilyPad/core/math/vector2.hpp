#pragma once

#include "LilyPad/core/utils/typedef.hpp"

namespace LilyPad
{
	struct Vector2
	{
		float x;
		float y;

		Vector2() : x(0.0f), y(0.0f) {}

		Vector2(float x, float y) : x(x), y(y) {}

		Vector2 clamp(float min_x, float max_x, float min_y, float max_y);

		Vector2 clamp(const Vector2 &min, const Vector2 &max);

		[[nodiscard]] Vector2 normalized() const;

		[[nodiscard]] bool is_normalized() const;

		[[nodiscard]] float magnitude() const;

		[[nodiscard]] float magnitude_squared() const;


		_FORCE_INLINE_ void operator+=(const Vector2 &other)
		{
			x += other.x;
			y += other.y;
		}

		_FORCE_INLINE_ Vector2 operator+(float scalar) const { return Vector2(x + scalar, y + scalar); }

		_FORCE_INLINE_ Vector2 operator-(float scalar) const { return Vector2(x - scalar, y - scalar); }

		_FORCE_INLINE_ Vector2 operator*(float scalar) const { return Vector2(x * scalar, y * scalar); }

		_FORCE_INLINE_ Vector2 operator/(float scalar) const { return Vector2(x / scalar, y / scalar); }

		_FORCE_INLINE_ Vector2 operator+(const Vector2 &other) const { return Vector2(x + other.x, y + other.y); }

		_FORCE_INLINE_ Vector2 operator-(const Vector2 &other) { return Vector2(x - other.x, y - other.y); }

		_FORCE_INLINE_ Vector2 operator*(const Vector2 &other) { return Vector2(x * other.x, y * other.y); }

		_FORCE_INLINE_ Vector2 operator/(const Vector2 &other) { return Vector2(x / other.x, y / other.y); }

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

		_FORCE_INLINE_ bool operator==(const Vector2 &other) const { return (x == other.x && y == other.y); }

		_FORCE_INLINE_ bool operator!=(const Vector2 &other) const { return (x != other.x && y != other.y); }

		_FORCE_INLINE_ bool operator>(const Vector2 &other) const { return x > other.x && y > other.y; }

		_FORCE_INLINE_ bool operator<(const Vector2 &other) const { return x < other.x && y < other.y; }

		_FORCE_INLINE_ bool operator>=(const Vector2 &other) const { return x >= other.x && y >= other.y; };

		_FORCE_INLINE_ bool operator<=(const Vector2 &other) const { return x <= other.x && y <= other.y; }
	};

	typedef Vector2 Point2;
} // namespace LilyPad