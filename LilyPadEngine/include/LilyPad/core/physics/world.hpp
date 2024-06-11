#pragma once

#include "LilyPad/core/math/vector2.hpp"
#include "LilyPad/core/physics/collision.hpp"
#include "LilyPad/core/physics/rigid_body_2d.hpp"

namespace LilyPad
{
	class World
	{
	public:
		World();
		World(Vector2 worldSize);

		/**
		 * @brief Applies the constant defined in constants.hpp to the rigidBody as a force vector.
		 *
		 * @param rigidBody Body being affected by gravity.
		 */
		void apply_gravity(RigidBody2D rigidBody);

	private:
		Vector2 _worldSize;
	};
} // namespace LilyPad