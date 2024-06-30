#include "LilyPad/core/math/matrix4.hpp"

namespace LilyPad
{
	Mat4::Mat4()
	{
		for (int i = 0; i < sizeof(data) / sizeof(float); i++)
		{
			data[i] = 0.0f;
		}
	}

	Mat4::Mat4(float value)
	{
		for (int i = 0; i < sizeof(data) / sizeof(float); i++)
		{
			data[i] = value;
		}
	}
} // namespace LilyPad
