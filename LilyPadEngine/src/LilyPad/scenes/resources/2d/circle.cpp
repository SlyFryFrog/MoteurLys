#include "LilyPad/scenes/resources/2d/circle.hpp"

namespace LilyPad
{
    Circle2D::Circle2D(float radius) : _radius(radius) {}

    float Circle2D::get_radius() { return _radius; }

    void Circle2D::set_radius(const float radius) { _radius = radius; }
} // namespace LilyPad
