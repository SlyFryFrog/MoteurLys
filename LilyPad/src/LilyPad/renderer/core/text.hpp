#pragma once

#include <freetype2/ft2build.h>
#include FT_FREETYPE_H
#include <map>
#include "LilyPad/core/math/vector2i.hpp"
#include "LilyPad/debug/logging.hpp"

namespace LilyPad
{
	struct Character
	{
		unsigned int id;	  // ID handle of the glyph texture
		Vector2i size;		  // Size of glyph
		Vector2i bearing;	  // Offset from baseline to left/top of glyph
		unsigned int advance; // Offset to advance to next glyph
	};

	class Text
	{
	public:
		void load_font(const std::string &path)
		{
			FT_Library ft;
			if (FT_Init_FreeType(&ft))
			{
				LILYPAD_CRITICAL("ERROR::FREETYPE: Could not init FreeType Library");
				return;
			}

			FT_Face face;
			if (FT_New_Face(ft, path.c_str(), 0, &face))
			{
				LILYPAD_CRITICAL("ERROR::FREETYPE: Failed to load font");
				return;
			}

			FT_Set_Pixel_Sizes(face, 0, 48);
			if (FT_Load_Char(face, 'X', FT_LOAD_RENDER))
			{
				LILYPAD_CRITICAL("ERROR::FREETYTPE: Failed to load Glyph");
				return;
			}
		}

	private:
		std::map<char, Character> Characters;
	};
} // namespace LilyPad
