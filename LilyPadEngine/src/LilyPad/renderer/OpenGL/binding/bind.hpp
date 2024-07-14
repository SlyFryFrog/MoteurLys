#pragma once

#include <GL/glew.h>
#include "LilyPad/renderer/OpenGL/vertex.hpp"

namespace LilyPad
{
	class Bind
	{
	public:
		Bind();
		~Bind()
		{
			glDeleteVertexArrays(1, &VAO);
			glDeleteBuffers(1, &VBO);
		}

		template <typename T>
		void bind_vertices(Vertices<T> vertices)
		{
			glBindVertexArray(VAO);
			vertices.bind_buffer(VBO);
		}

		void bind_vertex_array();

	private:
		unsigned int VAO; // Vertex array
		unsigned int VBO; // Data
		unsigned int EBO; // Indices
	};
} // namespace LilyPad
