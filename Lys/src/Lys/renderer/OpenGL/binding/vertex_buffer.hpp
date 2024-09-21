#pragma once

#include <GL/glew.h>
#include "Lys/renderer/OpenGL/vertex.hpp"

namespace Lys
{
	class VertexBuffer
	{
	public:
		VertexBuffer();
		~VertexBuffer();

		void bind() const;

		static void unbind();

		template <typename T>
		void set_data(Vertices<T> vertices) const
		{
			bind();
			glBufferData(GL_ARRAY_BUFFER, vertices.get_data().size() * sizeof(float),
						 vertices.get_data().data(), GL_STATIC_DRAW);
		}

		void set_data(int size, const void *data) const;

	private:
		unsigned int _VBO;
	};
} // namespace Lys
