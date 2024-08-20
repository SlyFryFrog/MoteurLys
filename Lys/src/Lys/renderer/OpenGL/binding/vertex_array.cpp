#include "vertex_array.hpp"

namespace Lys
{
	VertexArray::VertexArray() { glGenVertexArrays(1, &_VAO); }

	VertexArray::~VertexArray() { glDeleteVertexArrays(1, &_VAO); }

	void VertexArray::bind() const { glBindVertexArray(_VAO); }

	void VertexArray::unbind() { glBindVertexArray(0); }
} // namespace Lys
