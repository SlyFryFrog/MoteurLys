#include "LilyPad/core/rendering/texture.hpp"

#include <GL/glew.h>
#include <filesystem>
#include <stb_image.h>
#include "LilyPad/debug/logging.hpp"


namespace LilyPad
{
	Texture::Texture() {}

	Texture::Texture(const std::string &path) : _path(path) {}

	void Texture::set_path(const std::string &path) { _path = path; }

	std::string Texture::get_path() { return _path; }

	unsigned int Texture::generate_texture(const std::string &file)
	{
		unsigned int texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);

		// Set texture wrapping/filtering options (on currently bound texture object)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		int width, height, numColorChannel;
		stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
		unsigned char *data = stbi_load((_path + file).c_str(), &width, &height, &numColorChannel, 0);

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
				LILYPAD_ERROR("Unsupported file type. Could not determine correct number of channels.");
				format = 0;
				break;
			}

			glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
			LILYPAD_DEBUG("Successfully loaded texture data at the path ", _path, file, ".");
		}
		else
		{
			LILYPAD_ERROR("Failed to load texture data at the path ", _path, file,
						  ". Make sure the file format is supported or is in the appropriate location.");
		}

		stbi_image_free(data);

		return texture;
	}
} // namespace LilyPad