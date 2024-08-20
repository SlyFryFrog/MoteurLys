#pragma once

#include <glm/glm.hpp>
#include "Lys/core/math/vector3.hpp"
#include "Lys/scene/nodes/core/node.hpp"

namespace Lys
{
	class Node3D : public Node
	{
	public:
		Vector3 position; // Camera position in world space
		Vector3 absolutePosition;
		Vector3 size;
		Vector3 anchor;

		Node3D();

	private:
	};
} // namespace Lys
