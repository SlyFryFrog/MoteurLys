#include "camera_3d.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace LilyPad
{
	void Camera3D::look_at(Position3 point)
	{
		viewMatrix = glm::lookAt((glm::vec3)position, (glm::vec3)point, (glm::vec3)up);
		forward = (point - position).normalize();
	}
} // namespace LilyPad
