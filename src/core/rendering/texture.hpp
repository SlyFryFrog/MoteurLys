#pragma once

#include <string>

namespace LilyPad
{
	/**
	 * @brief Loads the desired texture file and returns the id of the texture. Sets the color channel automatically for
	 * a total number of color channels between 1-4.
	 *
	 * @param file          Path to the texture file.
	 * @return unsigned int ID of the loaded texture. Returns 0 if the texture failed to load.
	 *
	 * @note This function logs an error message if the texture fails to load or if the file format is unsupported.
	 * Example usage:
	 * \code{.cpp}
	 * unsigned int textureID = generate_texture("frog.png");
	 * if (textureID == 0) {
	 *     // Handle texture loading failure
	 * }
	 * \endcode
	 */
	unsigned int generate_texture(const std::string &file);
} // namespace LilyPad