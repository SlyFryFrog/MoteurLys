#pragma once

namespace LilyPad
{
	namespace LilyMath
	{
		template <typename T>
		const float *value_ptr(const T &object)
		{
            return static_cast<const float*>(object);
		}
	} // namespace LilyMath
} // namespace LilyPad
