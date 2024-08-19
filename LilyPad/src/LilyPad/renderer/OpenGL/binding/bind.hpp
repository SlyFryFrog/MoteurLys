#pragma once

#include <GL/glew.h>
#include "LilyPad/renderer/OpenGL/vertex.hpp"

namespace LilyPad
{
	class Bind
	{
	public:
		/**
		 * @brief Calls `glGenVertexArrays` and `glGenBuffers.
		 */
		Bind();

		/**
		 * @brief Calls `glDeleteVertexArrays` and `glDeleteBuffers` on binded data.
		 */
		~Bind();

		/**
		 * @brief Binds the VAO (Vertex Array Object) and then binds the VBO (Vertex Buffer Object).
		 *
		 * @tparam T Data being stored in the vertices.
		 * @param vertices The data to be binded.
		 */
		template <typename T>
		void bind_vertices(Vertices<T> vertices)
		{
			glBindVertexArray(VAO);
			vertices.bind_buffer(VBO);
		}

		/**
		 * @brief Binds the Vertex Array Object (VAO).
		 */
		void bind_vertex_array() const;

	private:
		unsigned int VAO; // Vertex array
		unsigned int VBO; // Data
		unsigned int EBO; // Indices
	};
} // namespace LilyPad
