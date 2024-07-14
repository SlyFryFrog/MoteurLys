#pragma once

#include "LilyPad/core/math/vector3.hpp"
#include "LilyPad/scene/nodes/3d/node_3d.hpp"

namespace LilyPad
{
	class Camera3D : public Node3D
	{
	public:
		fp_type yaw;
		fp_type pitch;
		Vector3 up;
		Vector3 forward;
		glm::mat4 viewMatrix;

		void look_at(Position3 point);

		Camera3D() = default;
	private:
	};
} // namespace LilyPad