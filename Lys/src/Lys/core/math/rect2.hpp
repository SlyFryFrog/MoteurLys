#pragma once

#include "Lys/core/math/vector2.hpp"

namespace Lys
{
	struct Rect2
	{
		Point2 position; // Top-left corner
		Vector2 size;

		Rect2(const Vector2 &p_size, const Point2 &p_position);

		void set_position(const Point2 &p_position);

		Vector2 get_position() const;

		void set_size(const Vector2 &p_size);

		Vector2 get_size() const;

		Vector2 get_center_position() const;

		float get_area() const;
	};
} // namespace Lys
