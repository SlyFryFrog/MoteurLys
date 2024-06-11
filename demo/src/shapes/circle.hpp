#pragma once

#include "LilyPad/core/physics/rigid_body_2d.hpp"

class Circle : public LilyPad::RigidBody2D
{
    void physics_process(float delta);
};