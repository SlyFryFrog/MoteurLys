#pragma once

#include <glm/glm.hpp>

namespace LilyPad
{
	struct Mat4
	{
		operator glm::mat4() const;
	};
} // namespace LilyPad