#pragma once

#include <string>
#include "Lys/core/io/file.hpp"
#include "Lys/core/io/image.hpp"

namespace Lys
{
	class Texture : File
	{
	public:
		unsigned int id;
		Texture();
		Texture(const std::string &path);

		/**
		 * @brief Reloads texture from the previously set path.
		 */
		void update() override;

		[[nodiscard]] unsigned int load_data(const std::string &file) const;

		[[nodiscard]] unsigned int load_data(const Image &image) const;

	private:
		[[nodiscard]] unsigned int set_attributes() const;
	};
} // namespace Lys