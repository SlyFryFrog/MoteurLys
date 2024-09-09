#pragma once

#include "Lys/renderer/core/abstract_renderer.hpp"

namespace Lys
{
	class RendererGL : public AbstractRenderer
	{
	public:
		RendererGL();
		~RendererGL() override;

		void init() override;
		void update_viewport(const int width, const int height) const override;
		void clear() const override;
	};
} // namespace Lys
