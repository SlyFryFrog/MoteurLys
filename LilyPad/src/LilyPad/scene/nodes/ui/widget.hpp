#pragma once

#include "LilyPad/scene/nodes/core/node.hpp"
#include "LilyPad/core/math/vector2.hpp"

namespace LilyPad
{
	class Widget : public Node
	{
	public:
		Widget();

		Vector2 position;
		Vector2 absolutePosition;
	private:
	};
} // namespace LilyPad
