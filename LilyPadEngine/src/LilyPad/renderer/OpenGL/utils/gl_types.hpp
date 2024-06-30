#pragma once

#include <GL/glew.h>

namespace LilyPad
{
	// Default template, will generate a compile-time error if used
	template <typename T>
	struct GLType;

	// Specializations for common types
	template <>
	struct GLType<float>
	{
		static constexpr GLenum value = GL_FLOAT;
	};

	template <>
	struct GLType<double>
	{
		static constexpr GLenum value = GL_DOUBLE;
	};

	template <>
	struct GLType<int>
	{
		static constexpr GLenum value = GL_INT;
	};

	template <>
	struct GLType<unsigned int>
	{
		static constexpr GLenum value = GL_UNSIGNED_INT;
	};

	template <>
	struct GLType<short>
	{
		static constexpr GLenum value = GL_SHORT;
	};

	template <>
	struct GLType<unsigned short>
	{
		static constexpr GLenum value = GL_UNSIGNED_SHORT;
	};

	template <>
	struct GLType<char>
	{
		static constexpr GLenum value = GL_BYTE;
	};

	template <>
	struct GLType<unsigned char>
	{
		static constexpr GLenum value = GL_UNSIGNED_BYTE;
	};
} // namespace LilyPad
