#pragma once

#include <glm/glm.hpp>

namespace LilyPad
{
	struct Mat4
	{
		float matrix[16];
		
		explicit operator glm::mat4() const;
	};
} // namespace LilyPad