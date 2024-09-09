#pragma once

#ifdef OPENGL
#include "Lys/renderer/OpenGL/opengl.hpp"
#endif

namespace Lys
{
	class Renderer
	{
		static Renderer *_singleton;
#ifdef OPENGL
		static RendererGL *_renderer;
#endif
	public:
		Renderer();

		static Renderer *get_singleton();

		void init();
		void clear();
		void update_viewport(const int width, const int height);
	};
} // namespace Lys
