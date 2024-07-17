#pragma once

#include <glm/glm.hpp>
#include "LilyPad/core/math/vector3.hpp"
#include "LilyPad/scene/nodes/3d/node_3d.hpp"

namespace LilyPad
{
	class Camera3D : public Node3D
	{
	public:
		float yaw;
		float pitch;
	    float mouseSensitivity;
    	bool constrainPitch;
		glm::vec3 up;
		glm::vec3 front;
		glm::vec3 right;
		glm::vec3 worldUp;
		glm::mat4 viewMatrix;
		float zoom;

		void look_at(const Position3 &point);

		glm::mat4 get_view();

		void update_view();

		Camera3D();

		void update_vectors();

		void process_mouse_movement(float xOffset, float yOffset);
	};
} // namespace LilyPad
