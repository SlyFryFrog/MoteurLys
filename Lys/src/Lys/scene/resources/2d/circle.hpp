#pragma once

#include "Lys/core/math/rect2.hpp"
#include "Lys/scene/resources/2d/shape.hpp"

namespace Lys
{
	class Circle2D : Shape2D
	{
	public:
		Circle2D(float radius);

	private:
		float _radius;

		float get_radius();

		void set_radius(float radius);

		virtual Rect2 get_rect() override;
	};
} // namespace Lys
