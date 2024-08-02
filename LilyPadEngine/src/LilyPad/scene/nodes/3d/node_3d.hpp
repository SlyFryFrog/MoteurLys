#pragma once

#include "LilyPad/core/math/vector3.hpp"
#include "LilyPad/scene/nodes/core/node.hpp"
#include <glm/glm.hpp>

namespace LilyPad
{
	class Node3D : public Node
	{
	public:
		glm::vec3 position;
		glm::vec3 absolutePosition;
		glm::vec3 size;

		Node3D();

	private:
	};
} // namespace LilyPad
