#pragma once

#include "LilyPad/core/math/vector2.hpp"
#include "LilyPad/scene/nodes/core/node.hpp"

namespace LilyPad
{
	class Node2D : public Node
	{
	public:
		Vector2 position;
		Vector2 absolutePosition;
	};
} // namespace LilyPad
