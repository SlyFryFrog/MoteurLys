#pragma once

#include <ft2build.h>
#include FT_FREETYPE_H
#include "Lys/scene/nodes/ui/widget.hpp"

namespace Lys
{
	class Label : public Widget
	{
	public:
		Label();
		Label(const std::string &text);

		std::string text;

	private:
	};
} // namespace Lys
