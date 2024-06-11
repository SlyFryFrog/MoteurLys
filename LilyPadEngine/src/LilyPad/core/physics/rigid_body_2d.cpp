#include "LilyPad/core/physics/rigid_body_2d.hpp"

namespace LilyPad
{
    RigidBody2D::RigidBody2D() {}
    
    void RigidBody2D::apply_force(const Vector2 &force)
    {
        // F = ma   ->   F/m = a   ->   a = F/m
        _acceleration = force / _mass;
    }
}