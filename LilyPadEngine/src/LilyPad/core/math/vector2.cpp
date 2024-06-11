#include "LilyPad/core/math/vector2.hpp"
#include <algorithm>
#include <cmath>

namespace LilyPad
{
	Vector2 Vector2::clamp(float min_x, float max_x, float min_y, float max_y)
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

	Vector2 Vector2::normalized() const
	{
		// Avoid division by zero
		if (magnitude() == 0)
		{
			return {0.0f, 0.0f}; // Return a zero vector if magnitude is zero
		}

		// Prevents doing sqrt on 0
		const float mag = magnitude_squared();

		// Divide each component by the magnitude
		return {x / mag, y / mag};
	}

	float Vector2::magnitude() const { return x * x + y * y; }

	float Vector2::magnitude_squared() const { return std::sqrt(x * x + y * y); }

	Vector2::operator glm::vec2() const { return {x, y}; }
} // namespace LilyPad