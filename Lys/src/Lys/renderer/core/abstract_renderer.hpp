#pragma once

namespace Lys
{
	class AbstractRenderer
	{
	public:
		AbstractRenderer() = default;
		virtual ~AbstractRenderer() = default;

		virtual void init() = 0;
		virtual void update_viewport(const int width, const int height) const = 0;
		virtual void clear() const = 0;
	};
} // namespace Lys
