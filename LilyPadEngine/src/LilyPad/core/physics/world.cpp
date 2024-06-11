#include "LilyPad/core/physics/world.hpp"
#include "LilyPad/core/math/vector2.hpp"
#include "LilyPad/core/utils/constants.hpp"

namespace LilyPad
{
	World::World() {}

	World::World(Vector2 worldSize) : _worldSize(worldSize) {}
	
	void World::apply_gravity(RigidBody2D rigidBody) { rigidBody.apply_force(Vector2(0, GRAVITY)); }
} // namespace LilyPad
