#include "image.hpp"

#include "LilyPad/debug/logging.hpp"

namespace LilyPad
{
	Image::Image() = default;
	Image::~Image() = default;

	void Image::set_pixel(int x_index, int y_index, const Color &data)
	{
		uint32_t offset = get_index(x_index, y_index);

		switch (_format)
		{
		case FORMAT_R8:
			_data[offset] = static_cast<uint8_t>(data.r * 255);
			break;
		case FORMAT_RG8:
			_data[offset] = static_cast<uint8_t>(data.r * 255);
			_data[offset + 1] = static_cast<uint8_t>(data.g * 255);
			break;
		case FORMAT_RGB8:
			_data[offset] = static_cast<uint8_t>(data.r * 255);
			_data[offset + 1] = static_cast<uint8_t>(data.g * 255);
			_data[offset + 2] = static_cast<uint8_t>(data.b * 255);
			break;
		case FORMAT_RGBA8:
			_data[offset] = static_cast<uint8_t>(data.r * 255);
			_data[offset + 1] = static_cast<uint8_t>(data.g * 255);
			_data[offset + 2] = static_cast<uint8_t>(data.b * 255);
			_data[offset + 3] = static_cast<uint8_t>(data.a * 255);
			break;
		default:
			break;
		}
	}

	void Image::set_data(int width, int height, bool useMipmaps, ImageFormat format, const std::vector<uint8_t> &data)
	{
		_width = width;
		_height = height;
		_useMipmaps = useMipmaps;
		_format = format;

		int expected_size = width * height * get_channel_count();
		if (data.size() != expected_size)
		{
			LILYPAD_ERROR("Data size does not match the expected size for the given dimensions and format.");
			return;
		}
		_data = data;
	}

	int Image::get_channel_count() const
	{
		return get_channel_count(_format);
	}

	int Image::get_channel_count(const ImageFormat &format)
	{
		switch (format)
		{
		case FORMAT_R8:
			return 1;
		case FORMAT_RG8:
			return 2;
		case FORMAT_RGB8:
			return 3;
		case FORMAT_RGBA8:
			return 4;
		default:
			break;
		}
		return 0;
	}

	int Image::get_index(int x, int y) const { return (y * _width + x) * get_channel_count(); }

	int Image::get_width() const { return _width; }

	int Image::get_height() const { return _height; }

	Vector2i Image::get_size() const { return {_width, _height}; }

	ImageFormat Image::get_format() const { return _format; }

	std::vector<uint8_t> Image::get_raw_data() const { return _data; }

	const uint8_t *Image::get_data() const { return _data.data(); }

	void Image::set_format(const ImageFormat &format) { _format = format; }
} // namespace LilyPad
