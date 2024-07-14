#pragma once

#include "LilyPad/scene/nodes/core/node.hpp"
#include "LilyPad/core/math/vector3.hpp"

namespace LilyPad
{
	class Node3D : public Node
	{
	public:
		Position3 position;
        Position3 absolutePosition;

        Node3D();

	private:
	};
} // namespace LilyPad
