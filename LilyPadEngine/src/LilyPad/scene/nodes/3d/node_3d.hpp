#pragma once

#include "LilyPad/scene/nodes/core/node.hpp"
#include "LilyPad/core/math/vector3.hpp"

namespace LilyPad
{
	class Node3D : Node
	{
	public:
		Position3 Position;
        Position3 AbsolutePosition;

        Node3D();

	private:
	};
} // namespace LilyPad
