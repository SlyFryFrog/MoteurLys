#pragma once

#include <GL/glew.h>
#include <vector>
#include "LilyPad/renderer/OpenGL/utils/gl_types.hpp"

namespace LilyPad
{
	template <typename T>
	struct Vertex
	{
		std::vector<std::vector<T>> data;

		// Constructor accepting an initializer list of initializer lists
		Vertex(std::initializer_list<std::initializer_list<T>> dataPoints)
		{
			for (const auto &points : dataPoints)
			{
				data.emplace_back(points);
			}
		}

		std::vector<T> get_data(int array_index) { return data[array_index]; }

		int size()
		{
			int size = 0;

			for (const auto &vector : data)
			{
				size += vector.size();
			}

			return size;
		}
	};

	template <typename T>
	class Vertices
	{
	public:
		std::vector<Vertex<T>> vertices;

		Vertices(std::initializer_list<Vertex<T>> verts) : vertices(verts) {}

		std::vector<T> get_data(int vertex_index, int array_index) { return vertices[vertex_index].get_data(array_index); }

		T *get_data()
		{
			std::vector<T> data;

			for (Vertex<T> vertex : vertices)
			{
				for (std::vector list : vertex.data)
				{
					for (T element : list)
					{
						data.push_back(element);
					}
				}
			}

			return data.data();
		}

		std::vector<T> get_vector()
		{
			std::vector<T> data;

			for (Vertex<T> vertex : vertices)
			{
				for (std::vector list : vertex.data)
				{
					for (T element : list)
					{
						data.push_back(element);
					}
				}
			}

			return data;
		}

		void bind_buffer(const unsigned int &VBO)
		{
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, get_vector().size() * sizeof(float), get_data(), GL_STATIC_DRAW);
		}

		void set_attributes()
		{
			int offset = 0;
			for (int i = 0; i < vertices[0].data.size(); i++)
			{
				GLint size = vertices[0].data[i].size();
				glVertexAttribPointer(i, size, GLType<T>::value, GL_FALSE, vertices[0].size() * sizeof(T),
									  (void *)(offset * sizeof(T)));
				glEnableVertexAttribArray(i);
				offset += size;
			}

			glBindVertexArray(0);
		}
	};
} // namespace LilyPad