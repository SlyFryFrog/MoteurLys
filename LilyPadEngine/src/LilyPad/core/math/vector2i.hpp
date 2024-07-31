#pragma once

#include "LilyPad/core/utils/typedef.hpp"

namespace LilyPad
{
    struct Vector2i
    {
        int x;
        int y;

		_FORCE_INLINE_ bool operator<=>(const Vector2i &other) const = default;
    };
} // namespace LilyPad
