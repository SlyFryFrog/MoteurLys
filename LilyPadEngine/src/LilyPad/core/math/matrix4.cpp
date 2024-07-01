#include "LilyPad/core/math/matrix4.hpp"

namespace LilyPad
{
	Mat4::Mat4()
	{
		for (float & i : data)
		{
			i = 0.0f;
		}
	}

	Mat4::Mat4(const float value)
	{
		for (float & i : data)
		{
			i = value;
		}
	}
} // namespace LilyPad
