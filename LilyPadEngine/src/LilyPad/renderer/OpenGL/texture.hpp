#pragma once

#include <string>
#include "LilyPad/core/io/file.hpp"
#include "LilyPad/core/io/image.hpp"

namespace LilyPad
{
	class Texture : File
	{
	public:
		unsigned int id;
		Texture();
		explicit Texture(const std::string &path);
		[[nodiscard]] unsigned int load_data(const std::string &file) const;

		/**
		 * @brief Reloads texture from the previously set path.
		 */
		void update() override;

		unsigned int load_data(const Image &image);

	private:
		std::string _path;
	};
} // namespace LilyPad