#include "renderer.hpp"

namespace Lys
{
	Renderer *Renderer::_singleton = nullptr;
#ifdef OPENGL
	RendererGL *Renderer::_renderer = nullptr;
#endif

	Renderer::Renderer()
	{
#ifdef OPENGL
		_renderer = new RendererGL();
#endif
	}

	Renderer *Renderer::get_singleton()
	{
		if (!_singleton)
			_singleton = new Renderer();

		return _singleton;
	}

	void Renderer::init() 
	{
		_renderer->init();
	}

	void Renderer::clear() { _renderer->clear(); }

	void Renderer::update_viewport(const int width, const int height)
	{
		_renderer->update_viewport(width, height);
	}
} // namespace Lys
