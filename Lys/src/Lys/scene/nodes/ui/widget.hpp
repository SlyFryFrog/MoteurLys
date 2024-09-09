#pragma once

#include "Lys/scene/nodes/core/node.hpp"
#include "Lys/core/math/vector2.hpp"

namespace Lys
{
	class Widget : public Node
	{
	public:
		Widget();

		Vector2 position;
		Vector2 absolutePosition;
	private:
	};
} // namespace Lys