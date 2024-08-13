#include "camera_3d.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace LilyPad
{
	Camera3D::Camera3D() :
		yaw(-90.0f), pitch(0.0f), mouseSensitivity(0.1f), constrainPitch(true), front(0.0f, 0.0f, -1.0f),
		worldUp(0.0f, 1.0f, 0.0f), zoom(45.0f)
	{
		update_vectors();
	}

	void Camera3D::look_at(const Position3 &point)
	{
        // Assuming you have the following member variables:
        // - Position3 position;  // Camera position in world space
        // - Vector3 forward;     // Forward vector (where the camera is looking at)
        // - Vector3 up;          // Up vector (camera's up direction)
        // - Vector3 right;       // Right vector (perpendicular to forward and up)
        
        // Step 1: Calculate the new forward vector (pointing from the camera's position to the target point)
        front = (point - position).normalize();
        
        // Step 2: Recalculate the right vector
        // Usually, the world up vector is (0, 1, 0), but this can change based on your coordinate system.
        const Vector3 world_up(0, 1, 0);
        right = world_up.cross(front).normalize();

        // Step 3: Recalculate the up vector
        up = front.cross(right).normalize();

        // Optionally, update the view matrix if your Camera3D class uses one
        //viewMatrix = Matrix4::look_at(position, point, up);
	}

	glm::mat4 Camera3D::get_view() const
	{
		return glm::lookAt(static_cast<glm::vec3>(position),
						   static_cast<glm::vec3>(position) + static_cast<glm::vec3>(front),
						   static_cast<glm::vec3>(up));
	}

	void Camera3D::update_view()
	{
		viewMatrix =
			glm::lookAt(static_cast<glm::vec3>(position),
						static_cast<glm::vec3>(position) + static_cast<glm::vec3>(front), static_cast<glm::vec3>(up));
	}

	void Camera3D::update_vectors()
	{
		Vector3 t_front;
		t_front.x = static_cast<fp_type>(cos(glm::radians(yaw)) * cos(glm::radians(pitch)));
		t_front.y = static_cast<fp_type>(sin(glm::radians(pitch)));
		t_front.z = static_cast<fp_type>(sin(glm::radians(yaw)) * cos(glm::radians(pitch)));
		front = Vector3::normalize(t_front);
		// also re-calculate the Right and Up vector
		right = Vector3::normalize(Vector3::cross(front, worldUp));
		up = Vector3::normalize(Vector3::cross(right, front));
	}

	void Camera3D::process_mouse_movement(float xOffset, float yOffset)
	{
		xOffset *= mouseSensitivity;
		yOffset *= mouseSensitivity;
		yaw += xOffset;
		pitch += yOffset;

		// make sure that when pitch is out of bounds, screen doesn't get flipped
		if (constrainPitch)
		{
			if (pitch > 89.0f)
				pitch = 89.0f;
			if (pitch < -89.0f)
				pitch = -89.0f;
		}

		update_vectors();
	}
} // namespace LilyPad
