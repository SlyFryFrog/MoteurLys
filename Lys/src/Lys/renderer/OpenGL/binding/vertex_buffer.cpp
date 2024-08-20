#include "vertex_buffer.hpp"

namespace Lys
{
	VertexBuffer::VertexBuffer() { glGenBuffers(1, &_VBO); }
	VertexBuffer::~VertexBuffer() { glDeleteBuffers(1, &_VBO); }

	void VertexBuffer::bind() const { glBindBuffer(GL_ARRAY_BUFFER, _VBO); }

	void VertexBuffer::unbind() { glBindBuffer(GL_ARRAY_BUFFER, 0); }

	void VertexBuffer::set_data(int size, const void *data) const
	{
		bind();
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	}

} // namespace Lys
