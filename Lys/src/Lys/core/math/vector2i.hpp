#pragma once

#include <compare>

namespace Lys
{
	struct Vector2i
	{
		int x;
		int y;

		bool operator<=>(const Vector2i &other) const = default;
	};
} // namespace Lys
