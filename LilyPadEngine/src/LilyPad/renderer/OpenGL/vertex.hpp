#pragma once

#include <vector>
#include "LilyPad/renderer/OpenGL/vertex.hpp"

namespace LilyPad
{
	struct Vertex
	{
		float position[3];
		float textureCoord[2];
	};

	struct VertexC : Vertex
	{
		float color[3];
	};

	class Vertices
	{
	public:
		Vertices();
		virtual void set_virtices(const std::vector<Vertex> vertices) = 0;
		virtual void add_vertex(const Vertex vertex) = 0;
		virtual void upload_vertices(unsigned int &VAO, unsigned int &VBO);
		virtual void upload_vertices(unsigned int &VAO, unsigned int &VBO, const int &row_size);

	protected:
		int _row_size;

	private:
		std::vector<Vertex> _vertices;
	};

	class VerticesC : public Vertices
	{
	public:
		VerticesC();
		// void set_vertices(const std::vector<VertexC> &vertices);
		// void add_vertex(const VertexC &vertex);
		// void upload_vertices(unsigned int &VAO, unsigned int &VBO, const int &row_size) override;

	private:
		std::vector<VertexC> _vertices;
	};

} // namespace LilyPad