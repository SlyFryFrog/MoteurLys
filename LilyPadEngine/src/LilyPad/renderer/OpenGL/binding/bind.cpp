#include "LilyPad/renderer/OpenGL/binding/bind.hpp"

namespace LilyPad
{
	Bind::Bind()
	{
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
	}

	void Bind::bind_vertex_array() const { glBindVertexArray(VAO); }
} // namespace LilyPad
