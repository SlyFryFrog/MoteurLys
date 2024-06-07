#pragma once

#include "core/typedef.hpp"
#include <glm/glm.hpp>

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

		Vector2 normalized() const;

		[[nodiscard]] bool is_normalized() const;

		[[nodiscard]] float magnitude() const;

		[[nodiscard]] float magnitude_squared() const;

		void operator+(const Vector2 &other);

		void operator-(const Vector2 &other);

		void operator*(const Vector2 &other);

		void operator/(const Vector2 &other);

		void operator+=(const Vector2 &other);

		void operator-=(const Vector2 &other);

		void operator*=(const Vector2 &other);

		void operator/=(const Vector2 &other);

		void operator==(const Vector2 &other);

		void operator!=(const Vector2 &other);

		void operator>(const Vector2 &other);

		bool operator<(const Vector2 &other);

		bool operator>=(const Vector2 &other);

		bool operator<=(const Vector2 &other);

		bool operator!=(const Vector2 &p_vec2) const { return x != p_vec2.x || y != p_vec2.y; }

		/**
		 * @brief Provides conversion for all data to glm::vec2
		 * 
		 * @return glm::vec2
		 */
		operator glm::vec2() const;
	};

	typedef Vector2 Point2;
} // namespace LilyPad