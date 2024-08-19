#include "circle.hpp"

namespace LilyPad
{
	Circle2D::Circle2D(float radius) : _radius(radius) {}

	float Circle2D::get_radius() { return _radius; }

	void Circle2D::set_radius(const float radius) { _radius = radius; }

	Rect2 Circle2D::get_rect() { return Rect2(Vector2(2 * _radius, 2 * _radius), position); }
} // namespace LilyPad
