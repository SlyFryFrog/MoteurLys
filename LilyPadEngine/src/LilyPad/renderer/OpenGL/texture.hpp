#pragma once

#include <string>

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

		unsigned int generate_texture(const std::string &file);

	private:
		std::string _path;
	};
} // namespace LilyPad