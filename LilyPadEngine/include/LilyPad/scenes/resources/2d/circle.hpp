#pragma once

#include "LilyPad/scenes/resources/2d/shape.hpp"

namespace LilyPad
{
	class Circle2D : Shape2D
	{
	public:
		Circle2D(float radius);

	private:
		float _radius;

		float get_radius();

		void set_radius(float radius);
	};
} // namespace LilyPad
