#include "LilyPad/core/math/rect2.hpp"

#include "LilyPad/core/math/vector2.hpp"

namespace LilyPad
{
	Rect2::Rect2(const Vector2 &p_size, const Point2 &p_position) : size(p_size), position(p_position) {}

	void Rect2::set_position(const Point2 &p_position) { position = p_position; }

	Vector2 Rect2::get_position() const { return position; }

	void Rect2::set_size(const Vector2 &p_size) { size = p_size; }

	Vector2 Rect2::get_size() const { return size; }

	Vector2 Rect2::get_center_position() const { return position + size * 0.5f; }

	float Rect2::get_area() const { return position.x * position.y; }
} // namespace LilyPad
