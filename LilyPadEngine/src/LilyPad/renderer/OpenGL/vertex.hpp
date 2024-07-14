#pragma once

#include <GL/glew.h>
#include <ostream>
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

		std::vector<T> get_data(int vertex_index, int array_index)
		{
			return vertices[vertex_index].get_data(array_index);
		}

		std::vector<T> get_data()
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
			glBufferData(GL_ARRAY_BUFFER, get_data().size() * sizeof(float), get_data().data(), GL_STATIC_DRAW);
		}

		void set_attributes()
		{
			int offset = 0;
			for (int i = 0; i < vertices[0].data.size(); i++)
			{
				GLint size = vertices[0].data[i].size();
				glVertexAttribPointer(i, size, GLType<T>::value, GL_FALSE, vertices[0].size() * sizeof(T),
									  static_cast<void *>(reinterpret_cast<char *>(offset * sizeof(T))));
				glEnableVertexAttribArray(i);
				offset += size;
			}

			glBindVertexArray(0);
		}

		friend std::ostream &operator<<(std::ostream &os, const Vertices<T> &obj)
		{
			os << "{";
			for (size_t i = 0; i < obj.vertices.size(); ++i)
			{
				if (i > 0)
					os << ", ";
				os << "{";
				for (size_t j = 0; j < obj.vertices[i].data.size(); ++j)
				{
					if (j > 0)
						os << ", ";
					os << "[";
					for (size_t k = 0; k < obj.vertices[i].data[j].size(); ++k)
					{
						if (k > 0)
							os << ", ";
						os << obj.vertices[i].data[j][k];
					}
					os << "]";
				}
				os << "}";
			}
			os << "}";
			return os;
		}
	};
} // namespace LilyPad