#pragma once

#include "Lys/renderer/core/renderer.hpp"

namespace Lys
{
	class RendererGL : public Renderer
	{
	public:
		RendererGL();
		void init() override;
		void update_viewport(const int width, const int height) const override;
	};
} // namespace Lys
