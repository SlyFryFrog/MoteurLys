#pragma once

#include <array>
#include <glm/glm.hpp>
#include "LilyPad/core/math/vector3.hpp"

namespace LilyPad
{
	struct Matrix4
	{
		std::array<std::array<float, 4>, 4> data;

		Matrix4()
		{
			for (int i = 0; i < 4; ++i)
				for (int j = 0; j < 4; ++j)
					data[i][j] = (i == j) ? 1.0f : 0.0f;
		}

		static Matrix4 look_at(const Vector3 &position, const Vector3 &point, const Vector3 &up);

		std::array<float, 4> &operator[](int index) { return data[index]; }

		Matrix4 operator*(const Matrix4 &other) const
		{
			Matrix4 result;
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					result.data[i][j] = 0.0f;
					for (int k = 0; k < 4; ++k)
					{
						result.data[i][j] += data[i][k] * other.data[k][j];
					}
				}
			}
			return result;
		}

		const std::array<float, 4> &operator[](int index) const { return data[index]; }


		operator float *() { return &data[0][0]; }

		operator const float *() const { return &data[0][0]; }
	};

} // namespace LilyPad
