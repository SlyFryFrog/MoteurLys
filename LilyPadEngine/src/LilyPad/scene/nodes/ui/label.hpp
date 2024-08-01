#pragma once

#include <ft2build.h>
#include FT_FREETYPE_H
#include "LilyPad/scene/nodes/ui/widget.hpp"

namespace LilyPad
{
	class Label : public Widget
	{
	public:
		Label();
		Label(const std::string &text);

		std::string text;

	private:
	};
} // namespace LilyPad
