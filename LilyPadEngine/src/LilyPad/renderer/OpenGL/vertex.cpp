#include "LilyPad/renderer/OpenGL/vertex.hpp"

#include <GL/glew.h>

namespace LilyPad
{
	Vertices::Vertices() : _row_size(5) {}

	void Vertices::upload_vertices(unsigned int &VAO, unsigned int &VBO) { upload_vertices(VAO, VBO, _row_size); }

	void Vertices::upload_vertices(unsigned int &VAO, unsigned int &VBO, const int &row_size)
	{
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, _vertices.size(), _vertices.data(), GL_STATIC_DRAW);

		// Position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, row_size * sizeof(float), (void *)0);
		glEnableVertexAttribArray(0);

		// Texture coord attribute
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, row_size * sizeof(float), (void *)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
		glBindVertexArray(0);
	}

	VerticesC::VerticesC() { _row_size = 8; }
	//
	// void VerticesC::set_vertices(const std::vector<VertexC> &vertices) { _vertices = vertices; }
	//
	// void VerticesC::add_vertex(const VertexC &vertex) { _vertices.push_back(vertex); }
	//
	// void VerticesC::upload_vertices(unsigned int &VAO, unsigned int &VBO, const int &row_size)
	// {
	// 	Vertices::upload_vertices(VAO, VBO);
	//
	// 	// Color coord attribute
	// 	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, row_size * sizeof(float), (void *)(5 * sizeof(float)));
	// 	glEnableVertexAttribArray(1);
	// 	glBindVertexArray(0);
	// }
} // namespace LilyPad