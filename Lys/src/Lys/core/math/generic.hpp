#pragma once

namespace Lys
{
	namespace LysMath
	{
		template <typename T>
		const float *value_ptr(const T &object)
		{
            return static_cast<const float*>(object);
		}
	} // namespace LysMath
} // namespace Lys
