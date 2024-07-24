#pragma once

#include <ft2build.h>
#include FT_FREETYPE_H
#include "LilyPad/scene/nodes/ui/widget.hpp"

namespace LilyPad
{
	class Label : public Widget
	{
	public:
		Label()
		{
			FT_Library ft;
			// if (FT_Init_FreeType(&ft))
			// {
			// }

			FT_Face face;
			// if (FT_New_Face(ft, "fonts/arial.ttf", 0, &face))
			// {
			// }
		}

	private:
	};
} // namespace LilyPad
