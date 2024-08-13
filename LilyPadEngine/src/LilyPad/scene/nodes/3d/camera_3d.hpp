#pragma once

#include <glm/glm.hpp>
#include "LilyPad/core/math/matrix4.hpp"
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
		Vector3 up{};
		Vector3 front;
		Vector3 right{};
		Vector3 worldUp;
		glm::mat4 viewMatrix{};
		float zoom;

		Camera3D();

		/**
		 * @brief Sets the camera's view matrix to look at a specified point.
		 *
		 * This function updates the camera's view matrix to orient the camera such that it looks at
		 * the given point in 3D space. The view matrix is calculated based on the camera's current position
		 * and the specified point, while maintaining the camera's up direction as defined by `worldUp`.
		 *
		 * @param point The target position in 3D space that the camera should look at.
		 *
		 * Example usage:
		 * @code
		 * Position3 targetPoint = {1.0f, 2.0f, 3.0f};
		 * camera.look_at(targetPoint);
		 * @endcode
		 */
		void look_at(const Position3 &point);

		[[nodiscard]] glm::mat4 get_view() const;

		void update_view();

		void update_vectors();

		void process_mouse_movement(float xOffset, float yOffset);
	};
} // namespace LilyPad
