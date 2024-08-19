#pragma once

#include "Lys/core/math/vector2.hpp"
#include "Lys/core/math/rect2.hpp"

namespace Lys
{
	class Shape2D
	{
	protected:
		Point2 position;

	public:
		virtual Rect2 get_rect() = 0;
	};
} // namespace Lys
