#pragma once

#include <glm/glm.hpp>
#include <vector>
#include "LilyPad/core/math/vector2.hpp"

namespace LilyPad
{
	struct Vertex
	{
		glm::vec3 position;
		glm::vec2 textureCoord;
	};

	struct VertexC : public Vertex
	{
		glm::vec3 color;
	};

	// class Vertices
	// {
	// public:
	// 	Vertices();
	// 	virtual void set_virtices(std::vector<Vertex> vertices);
	// 	virtual void add_vertex(Vertex vertex);
	// 	virtual void upload_vertices(unsigned int &VAO, unsigned int &VBO);
	// 	virtual void upload_vertices(unsigned int &VAO, unsigned int &VBO, int row_size);

	// protected:
	// 	int _row_size;

	// private:
	// 	std::vector<Vertex> _vertices;
	// };

	// class VerticesC : public Vertices
	// {
	// public:
	// 	VerticesC();
	// 	void set_vertices(std::vector<VertexC> vertices);
	// 	void add_vertex(VertexC vertex);
	// 	void upload_vertices(unsigned int &VAO, unsigned int &VBO, int row_size) override;

	// private:
	// 	std::vector<VertexC> _vertices;
	// };

} // namespace LilyPad