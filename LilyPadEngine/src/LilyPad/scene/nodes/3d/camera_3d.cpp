#include "camera_3d.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace LilyPad
{
	Camera3D::Camera3D() = default;

	void Camera3D::look_at(const Position3 &point)
	{
		viewMatrix =
			glm::lookAt(static_cast<glm::vec3>(position), static_cast<glm::vec3>(point), static_cast<glm::vec3>(up));
	}

	glm::mat4 Camera3D::get_view()
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
		Vector3 front;
		front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
		front.y = sin(glm::radians(pitch));
		front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
		front = Vector3::normalize(front);
		right = Vector3::normalize(Vector3::cross(front, up));
		up = Vector3::normalize(Vector3::cross(right, front));
	}
} // namespace LilyPad
