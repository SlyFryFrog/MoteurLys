#pragma once

namespace Lys
{
	class Renderer
	{
	public:
        Renderer();
		virtual void init() = 0;
		virtual void update_viewport(const int width, const int height) const = 0;
	};
} // namespace Lys
