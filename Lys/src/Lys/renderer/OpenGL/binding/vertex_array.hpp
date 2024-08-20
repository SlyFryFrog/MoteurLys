#pragma once

#include <GL/glew.h>

namespace Lys
{
	class VertexArray
	{
	public:
		VertexArray();
		~VertexArray();

		void bind() const;
		static void unbind();

	private:
		unsigned int _VAO;
	};
} // namespace Lys
