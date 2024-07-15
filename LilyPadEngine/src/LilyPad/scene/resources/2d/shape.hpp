#pragma once

#include "LilyPad/core/math/vector2.hpp"
#include "LilyPad/core/math/rect2.hpp"

namespace LilyPad
{
	class Shape2D
	{
	protected:
		Point2 position;

	public:
		virtual Rect2 get_rect() = 0;
	};
} // namespace LilyPad
