#include "Lys/renderer/OpenGL/binding/bind.hpp"

namespace Lys
{
	Bind::Bind()
	{
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
	}

	Bind::~Bind()
	{
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
	}

	void Bind::bind_vertex_array() const { glBindVertexArray(VAO); }
} // namespace Lys
