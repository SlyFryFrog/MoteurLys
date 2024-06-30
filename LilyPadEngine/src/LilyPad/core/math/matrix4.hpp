#pragma once

#include <iostream>

namespace LilyPad
{
	struct Mat4
	{
		float data[16];

		Mat4 operator+(const Mat4 &other)
		{
			Mat4 result;
			for (int i = 0; i < 16; ++i)
			{
				result.data[i] = data[i] + other.data[i];
			}
			return result;
		}

		Mat4 operator-(const Mat4 &other)
		{
			Mat4 result;
			for (int i = 0; i < 16; ++i)
			{
				result.data[i] = data[i] - other.data[i];
			}
			return result;
		}

		Mat4 operator*(const Mat4 &other)
		{
			Mat4 result;
			for (int i = 0; i < 16; ++i)
			{
				result.data[i] = data[i] * other.data[i];
			}
			return result;
		}

		Mat4 operator/(const Mat4 &other)
		{
			Mat4 result;
			for (int i = 0; i < 16; ++i)
			{
				result.data[i] = data[i] / other.data[i];
			}
			return result;
		}

		/**
		 * @brief Prints a grid view of the matrix data in rows from 0-3, 4-7, 8-11, 12-15.
		 */
		void print() const
		{
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					std::cout << data[i * 4 + j] << ' ';
				}
				std::cout << std::endl;
			}
		}
	};
} // namespace LilyPad