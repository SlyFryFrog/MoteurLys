#include "LilyPad/core/math/matrix4.hpp"

namespace LilyPad
{
	Mat4::operator glm::mat4() const
	{
		return glm::mat4(matrix[0], matrix[1], matrix[2], matrix[3], matrix[4], matrix[5], matrix[6], matrix[7],
						 matrix[8], matrix[9], matrix[10], matrix[11], matrix[12], matrix[13], matrix[14], matrix[15]);
	}
} // namespace LilyPad
