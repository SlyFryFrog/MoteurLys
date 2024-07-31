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
		FORMAT_R8,
		FORMAT_RG8,
		FORMAT_RGB8,
		FORMAT_RGBA8
	};

	class Image : public File
	{
	public:
		Image();
		~Image();

		void set_data(int width, int height, bool useMipmaps, ImageFormat format, const std::vector<uint8_t> &data);
		void set_pixel(int x_index, int y_index, const Color &data);
		void load(const std::string &path);

		int get_width() const;
		int get_height() const;
		Vector2i get_size() const;

		ImageFormat get_format() const;
		void set_format(const ImageFormat &format);

		std::vector<uint8_t> get_raw_data() const;
		const uint8_t *get_data() const;

	private:
		int _width;
		int _height;
		bool _useMipmaps;
		std::vector<uint8_t> _data;
		ImageFormat _format;

		int get_channel_count() const;
		int get_index(int x, int y) const;
	};
} // namespace LilyPad
