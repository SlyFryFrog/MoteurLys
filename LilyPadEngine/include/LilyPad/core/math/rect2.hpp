#pragma once

#include "LilyPad/core/math/vector2.hpp"

namespace LilyPad
{
	struct Rect2
	{
		Point2 position; // Top-left corner
		Vector2 size;

		void set_position(const Point2 &p_position);

		Vector2 get_position() const;

		void set_size(const Vector2 &p_size);

		Vector2 get_size() const;

		Vector2 get_center_position() const;

		float get_area() const;
	};

} // namespace LilyPad
