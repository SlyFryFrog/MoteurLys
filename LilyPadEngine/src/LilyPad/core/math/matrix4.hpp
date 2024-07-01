#pragma once

#include <ostream>

namespace LilyPad
{
	struct Mat4
	{
		float data[16]{};

		/**
		 * @brief Creates a new object with values set to 0.0f.
		 */
		Mat4();

		/**
		 * @brief Sets all data in the matrix to the input value.
		 */
		explicit Mat4(float value);

		Mat4 operator+(const Mat4 &other) const
		{
			Mat4 result;
			for (int i = 0; i < 16; ++i)
			{
				result.data[i] = data[i] + other.data[i];
			}
			return result;
		}

		Mat4 operator-(const Mat4 &other) const
		{
			Mat4 result;
			for (int i = 0; i < 16; ++i)
			{
				result.data[i] = data[i] - other.data[i];
			}
			return result;
		}

		Mat4 operator*(const Mat4 &other) const
		{
			Mat4 result;
			for (int i = 0; i < 16; ++i)
			{
				result.data[i] = data[i] * other.data[i];
			}
			return result;
		}

		Mat4 operator/(const Mat4 &other) const
		{
			Mat4 result;
			for (int i = 0; i < 16; ++i)
			{
				result.data[i] = data[i] / other.data[i];
			}
			return result;
		}

		friend std::ostream &operator<<(std::ostream &os, const Mat4 &obj)
		{
			os << "{";
			for (int i = 0; i < 4; ++i)
			{
				os << "[";
				for (int j = 0; j < 4; ++j)
				{
					os << obj.data[i * 4 + j] << ' ';
				}
				os << "]";
			}
			os << "}";

			return os;
		}
	};
} // namespace LilyPad