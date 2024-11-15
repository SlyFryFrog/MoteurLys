#include "texture.hpp"

#include <GL/glew.h>
#include <filesystem>
#include <stb_image.h>
#include "Lys/debug/logging.hpp"


namespace Lys
{
	Texture::Texture() = default;
	Texture::Texture(const std::string &path) : File(path) {}

	void Texture::update()
	{
		if (is_updated())
		{
			_lastTime = std::filesystem::last_write_time(_path);

			if (_path.c_str())
			{
				id = load_data(_path);
			}
		}
	}

	unsigned int Texture::load_data(const std::string &file) const
	{
		unsigned int texture = set_attributes();

		int width, height, numColorChannel;
		stbi_set_flip_vertically_on_load(
			true); // tell stb_image.h to flip loaded texture's on the y-axis.
		unsigned char *data =
			stbi_load((_path + file).c_str(), &width, &height, &numColorChannel, 0);

		if (data)
		{
			// Checks which type of color channel is being used by the file.
			GLint format;
			switch (numColorChannel)
			{
			case 1:
				format = GL_RED;
				break;
			case 2:
				format = GL_RG;
				break;
			case 3:
				format = GL_RGB;
				break;
			case 4:
				format = GL_RGBA;
				break;
			default:
				LYS_ERROR("Unsupported file type. Could not determine correct number of channels.");
				format = 0;
				break;
			}

			glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE,
						 data);
			glGenerateMipmap(GL_TEXTURE_2D);
			LYS_DEBUG("Successfully loaded texture data at the path ", _path, file, ".");
		}
		else
		{
			LYS_ERROR(
				"Failed to load texture data at the path ", _path, file,
				". Make sure the file format is supported or is in the appropriate location.");
		}

		stbi_image_free(data);

		return texture;
	}

	unsigned int Texture::load_data(const Image &image) const
	{
		unsigned int texture = set_attributes();
		const uint8_t *data = image.get_data();

		if (data != nullptr)
		{
			// Checks which type of color channel is being used by the file.
			GLint format;
			switch (image.get_format())
			{
			case ImageFormat::R8:
				format = GL_RED;
				break;
			case ImageFormat::RG8:
				format = GL_RG;
				break;
			case ImageFormat::RGB8:
				format = GL_RGB;
				break;
			case ImageFormat::RGBA8:
				format = GL_RGBA;
				break;
			default:
				LYS_ERROR("Unsupported file type. Could not determine correct number of channels.");
				format = 0;
				break;
			}

			glTexImage2D(GL_TEXTURE_2D, 0, format, image.get_width(), image.get_height(), 0, format,
						 GL_UNSIGNED_BYTE, image.get_data());
			glGenerateMipmap(GL_TEXTURE_2D);
			LYS_DEBUG("Successfully loaded texture data at the path.");
		}
		else
		{
			LYS_ERROR("Failed to load texture data.");
		}

		return texture;
	}

	unsigned int Texture::set_attributes() const
	{
		// Ignores unnecessary deletion for empty id
		if (id)
		{
			glDeleteTextures(1, &id);
		}

		unsigned int texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);

		// Set texture wrapping/filtering options (on currently bound texture object)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		return texture;
	}
} // namespace Lys
