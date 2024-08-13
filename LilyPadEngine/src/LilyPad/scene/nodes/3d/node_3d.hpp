#pragma once

#include "LilyPad/core/math/vector3.hpp"
#include "LilyPad/scene/nodes/core/node.hpp"
#include <glm/glm.hpp>

namespace LilyPad
{
	class Node3D : public Node
	{
	public:
		Vector3 position;
		Vector3 absolutePosition;
		Vector3 size;

		Node3D();

	private:
	};
} // namespace LilyPad
