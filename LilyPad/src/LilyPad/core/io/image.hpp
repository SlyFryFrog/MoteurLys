#pragma once

#include <string>
#include <vector>
#include "LilyPad/core/io/file.hpp"
#include "LilyPad/core/math/color.hpp"
#include "LilyPad/core/math/vector2i.hpp"

namespace LilyPad
{
	enum class ImageFormat
	{
		R8,
		RG8,
		RGB8,
		RGBA8
	};

	class Image : public File
	{
	public:
		Image();
		~Image();

		void set_data(int width, int height, bool useMipmaps, ImageFormat format, const std::vector<uint8_t> &data);

		/**
		 * @brief Sets the color of a specific pixel in the image.
		 *
		 * This method updates the color of the pixel at the specified (x, y) coordinates
		 * in the image with the provided color data.
		 *
		 * @param x_index The x-coordinate of the pixel to be set.
		 * @param y_index The y-coordinate of the pixel to be set.
		 * @param data The color data to set the pixel to.
		 */
		void set_pixel(int x_index, int y_index, const Color &data);

		/**
		 * @return int Width of the image.
		 */
		int get_width() const;

		/**
		 * @return int Height of the image.
		 */
		int get_height() const;

		/**
		 * @return Vector2i Returns the size of the image as a Vector2 integer in the form (width, height).
		 */
		Vector2i get_size() const;

		ImageFormat get_format() const;
		void set_format(const ImageFormat &format);

		std::vector<uint8_t> get_raw_data() const;
		const uint8_t *get_data() const;

		static int get_channel_count(const ImageFormat &format);

		/**
		 * @return int Number of channels for the current image format.
		 */
		int get_channel_count() const;

	private:
		int _width;
		int _height;
		bool _useMipmaps; // Currently unused
		std::vector<uint8_t> _data;
		ImageFormat _format;

		/**
		 * @brief Get the starting index of the pixel segment.
		 *
		 * @param x X position of the pixel.
		 * @param y Y position of the pixel.
		 * @return int Starting position of the pixel in a 1-dimensional list.
		 */
		int get_index(int x, int y) const;
	};
} // namespace LilyPad
