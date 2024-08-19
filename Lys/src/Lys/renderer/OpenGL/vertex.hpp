#pragma once

#include <GL/glew.h>
#include <ostream>
#include <vector>
#include "Lys/renderer/OpenGL/utils/gl_types.hpp"

namespace Lys
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

		/**
		 * @brief Returns the 1D sub array at the given index.
		 *
		 * @param index Index of the requested array.
		 * @return std::vector<T> Data of the array.
		 */
		std::vector<T> get_data(int index) { return data[index]; }

		/**
		 * @brief Gets the size of the 2D array.
		 *
		 * @return int Total number of elements.
		 */
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

		/**
		 * @brief Gets the data from all Vertices in a single 1-dimensional array. It retains the original order of the
		 * elements.
		 *
		 * @return std::vector<T> Array containing data from all Vertices.
		 */
		std::vector<T> get_data()
		{
			std::vector<T> data; // Converted data from 3D array to 1D array

			for (Vertex<T> vertex : vertices)
			{
				for (std::vector<T> list : vertex.data)
				{
					for (T element : list)
					{
						data.push_back(element);
					}
				}
			}

			return data;
		}

		/**
		 * @brief Binds a buffer and uploads vertex data to it for OpenGL rendering.
		 *
		 * This function binds a given Vertex Buffer Object (VBO) and uploads the vertex data to it.
		 * It uses `glBindBuffer` to bind the buffer and `glBufferData` to create and initialize the buffer's data
		 * store. The function assumes that `get_data()` returns a vector of vertex data that needs to be uploaded to
		 * the GPU.
		 *
		 * @param VBO A constant reference to an unsigned int representing the Vertex Buffer Object ID.
		 *
		 * @note Ensure that `get_data()` returns the appropriate vertex data before calling this function.
		 *
		 * Example usage:
		 * @code
		 * unsigned int VBO;
		 * glGenBuffers(1, &VBO);
		 * bind_buffer(VBO);
		 * @endcode
		 */
		void bind_buffer(const unsigned int &VBO)
		{
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, get_data().size() * sizeof(float), get_data().data(), GL_STATIC_DRAW);
		}

		/**
		 * @brief Sets the vertex attribute pointers for OpenGL rendering.
		 *
		 * This function iterates over the vertex data and sets up the vertex attribute pointers.
		 * It uses `glVertexAttribPointer` to specify the location and data format of the array of
		 * generic vertex attributes and enables the attribute array with `glEnableVertexAttribArray`.
		 * The function assumes that `vertices` is a properly populated vector of vertex data where
		 * each vertex has the same structure.
		 *
		 * @tparam T The data type of the vertex attributes (e.g. float or double).
		 *
		 * @note This function assumes that the VAO (Vertex Array Object) has been bound before
		 * calling it, and unbinds the VAO at the end.
		 *
		 * Example usage:
		 * @code
		 * Vertices<float> vertices({{{-1.0f, 1.0f, 0.0f}, {0.0f, 1.0f}}});
		 * Bind bind;
		 * bind.bind_vertices(vertices); // Data must be binded before setting the attributes.
		 * vertices.set_attributes();
		 * @endcode
		 */
		void set_attributes()
		{
			int offset = 0;
			for (int i = 0; i < vertices[0].data.size(); i++)
			{
				GLint size = vertices[0].data[i].size();

				// index; size; type of data as GLType; normalized; stride; pointer
				glVertexAttribPointer(i, size, GLType<T>::value, GL_FALSE, vertices[0].size() * sizeof(T),
									  static_cast<void *>(reinterpret_cast<char *>(offset * sizeof(T))));
				glEnableVertexAttribArray(i);
				offset += size; // Shifts starting point for next data
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
} // namespace Lys