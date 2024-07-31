#pragma once

#include <string>
#include "LilyPad/core/io/image.hpp"

namespace LilyPad
{
	class Texture
	{
	public:
		unsigned int id;
		Texture();

		explicit Texture(const std::string &path);

		void set_path(const std::string &path);

		std::string get_path();

		[[nodiscard]] unsigned int generate_texture(const std::string &file) const;

		unsigned int load_data(const Image &image);
	private:
		std::string _path;
	};
} // namespace LilyPad