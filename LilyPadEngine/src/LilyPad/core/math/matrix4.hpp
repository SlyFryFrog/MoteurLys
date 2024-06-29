#pragma once

namespace LilyPad
{
	struct Mat4
	{
		float matrix[16];
		
		Mat4 operator+(const Mat4 &other) { return Mat4(); }
	};
} // namespace LilyPad