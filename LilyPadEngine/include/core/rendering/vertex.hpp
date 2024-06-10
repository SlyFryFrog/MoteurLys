#pragma once
#include <glm/glm.hpp>

namespace LilyPad
{
	/**
	 * @struct Vertex
	 * @brief Represents a 3D vertex with position and texture coordinates.
	 *
	 * This struct encapsulates the attributes of a 3D vertex which includes
	 * its position in 3D space and its corresponding texture coordinates.
	 */
	struct Vertex
	{
		/**
		 * @brief The position of the vertex in 3D space.
		 *
		 * This is a 3D vector representing the x, y, and z coordinates of the vertex.
		 */
		glm::vec3 position;

		/**
		 * @brief The texture coordinates of the vertex.
		 *
		 * This is a 2D vector representing the s and t texture coordinates for texture mapping.
		 */
		glm::vec2 textureCoord;
	};

	/**
	 * @struct VertexC
	 * @brief Represents a colored 3D vertex with position, texture, and color coordinates.
	 *
	 * This struct extends the Vertex struct by adding a color attribute to the vertex,
	 * allowing for more complex rendering that includes vertex coloring.
	 */
	struct VertexC : Vertex
	{
		/**
		 * @brief The color coordinates of the vertex.
		 *
		 * This is a 3D vector representing the RGB color values of the vertex.
		 */
		glm::vec3 color;
	};

} // namespace LilyPad