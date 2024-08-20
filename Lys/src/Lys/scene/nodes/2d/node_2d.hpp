#pragma once

#include "Lys/core/math/vector2.hpp"
#include "Lys/scene/nodes/core/node.hpp"

namespace Lys
{
	class Node2D : public Node
	{
	public:
		Vector2 position;
		Vector2 absolutePosition;
		Vector2 size;
		Vector2 anchor;
	};
} // namespace Lys
