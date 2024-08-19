#pragma once

#include "Lys/core/math/vector3.hpp"
#include "Lys/scene/nodes/core/node.hpp"
#include <glm/glm.hpp>

namespace Lys
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
} // namespace Lys
