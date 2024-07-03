#include "LilyPad/core/math/matrix4.hpp"

namespace LilyPad
{
	Mat4::Mat4()
	{
		for (float &i : data)
		{
			i = 0.0f;
		}
	}

	Mat4::Mat4(const float value)
	{
		for (float &i : data)
		{
			i = value;
		}
	}

	Mat4 Mat4::translate(const Mat4 &model, const Vector3 &translation)
	{
		Mat4 result = model;
		result.data[3] = translation.x;
		result.data[7] = translation.y;
		result.data[11] = translation.z;
		return result;
	}
} // namespace LilyPad
