#pragma once

#include "core/math/vector2.hpp"
#include "core/physics/collision.hpp"
#include "core/physics/rigid_body_2d.hpp"

namespace LilyPad
{
	class World
	{
	public:
		void apply_gravity(RigidBody2D rigidBody);

	private:
		Vector2 _worldSize;
	};
} // namespace LilyPad