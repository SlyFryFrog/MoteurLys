#include "LilyPad/core/math/vector2.hpp"
#include <algorithm>
#include <cmath>
#include "LilyPad/core/utils/typedef.hpp"

namespace LilyPad
{
	Vector2 Vector2::clamp(const fp_type min_x, const fp_type max_x, const fp_type min_y, const fp_type max_y)
	{
		x = std::clamp(x, min_x, max_x);
		y = std::clamp(y, min_y, max_y);
		return {x, y};
	}

	Vector2 Vector2::clamp(const Vector2 &min, const Vector2 &max)
	{
		x = std::clamp(x, min.x, max.x);
		y = std::clamp(y, min.y, max.y);
		return {x, y};
	}

	fp_type Vector2::dot_product(const Vector2 &p_vec1, const Vector2 &p_vec2)
	{
		return p_vec1.x * p_vec2.x + p_vec1.y * p_vec2.y;
	}

	fp_type Vector2::dot_product(const Vector2 &p_vec1, const Vector2 &p_vec2, const fp_type &theta)
	{
		return (fp_type) (std::abs(p_vec1.magnitude()) * std::abs(p_vec2.magnitude()) * std::cos(theta));
	}

	Vector2 Vector2::normalized() const
	{
		// Avoid division by zero
		if (magnitude() == 0)
		{
			return {0.0f, 0.0f}; // Return a zero vector if magnitude is zero
		}

		// Prevents doing sqrt on 0
		const fp_type mag = magnitude_squared();

		// Divide each component by the magnitude
		return {x / mag, y / mag};
	}

	fp_type Vector2::magnitude() const { return x * x + y * y; }

	fp_type Vector2::magnitude_squared() const { return std::sqrt(x * x + y * y); }
} // namespace LilyPad