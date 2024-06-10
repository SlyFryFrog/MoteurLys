#include "core/physics/world.hpp"
#include "core/math/vector2.hpp"
#include "core/utils/constants.hpp"

namespace LilyPad
{
	void World::apply_gravity(RigidBody2D rigidBody)
	{	
		rigidBody.apply_force(Vector2(0, GRAVITY));
	}
} // namespace LilyPad
