#include "camera_3d.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace LilyPad
{
	Camera3D::Camera3D() 
		: yaw(-90.0f), pitch(0.0f), mouseSensitivity(0.1f), constrainPitch(true), 
		  front(glm::vec3(0.0f, 0.0f, -1.0f)), worldUp(glm::vec3(0.0f, 1.0f, 0.0f)), zoom(45.0f)
	{
		update_vectors();
	}

	void Camera3D::look_at(const Position3 &point)
	{
		viewMatrix = glm::lookAt(static_cast<glm::vec3>(position), static_cast<glm::vec3>(point), worldUp);
	}

	glm::mat4 Camera3D::get_view()
	{
		return glm::lookAt(static_cast<glm::vec3>(position),
						   static_cast<glm::vec3>(position) + static_cast<glm::vec3>(front),
						   static_cast<glm::vec3>(up));
	}

	void Camera3D::update_view()
	{
		viewMatrix = glm::lookAt(static_cast<glm::vec3>(position),
								 static_cast<glm::vec3>(position) + static_cast<glm::vec3>(front), 
								 static_cast<glm::vec3>(up));
	}

	void Camera3D::update_vectors()
	{
		glm::vec3 t_front;
		t_front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
		t_front.y = sin(glm::radians(pitch));
		t_front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
		front = glm::normalize(t_front);
		// also re-calculate the Right and Up vector
		right = glm::normalize(glm::cross(front, worldUp)); 
		up = glm::normalize(glm::cross(right, front));
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
