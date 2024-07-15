#pragma once

#include "LilyPad/core/math/vector3.hpp"
#include "LilyPad/scene/nodes/3d/node_3d.hpp"

namespace LilyPad
{
	class Camera3D : public Node3D
	{
	public:
		float yaw;
		float pitch;
		Vector3 up;
		Vector3 front;
		Vector3 right;
		glm::mat4 viewMatrix;

		void look_at(const Position3 &point);

		glm::mat4 get_view();

		void update_view();

		Camera3D();
		
		void update_vectors();
	};
} // namespace LilyPad