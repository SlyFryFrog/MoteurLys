#pragma once

#include <glm/glm.hpp>

namespace LilyPad
{
	struct Mat4
	{
		float matrix[16];
		
		explicit operator glm::mat4() const;

		Mat4 operator+(const Mat4 &other) { return Mat4(); }
	};
} // namespace LilyPad