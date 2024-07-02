#pragma once

#include <GL/glew.h>
#include "LilyPad/renderer/OpenGL/vertex.hpp"

namespace LilyPad
{
	class Bind
	{
	public:
		Bind();

		template <typename T>
		void bind_vertices(Vertices<T> vertices)
		{
            glBindVertexArray(VAO);
            vertices.bind_buffer(VBO);
		}

	private:
		unsigned int VAO; // Vertex array
		unsigned int VBO; // Data
		unsigned int EBO; // Indices
	};
} // namespace LilyPad
