#pragma once

#include "core/math/vector2.hpp"
#include "core/physics/collision.hpp"

namespace LilyPad
{
	class World
	{
	public:
		void apply_gravity();
	private:
		Vector2 _worldSize;
	};
} // namespace LilyPad