#include "opengl.hpp"

#include <GL/glew.h>
#include "Lys/debug/logging.hpp"

namespace Lys
{
	RendererGL::RendererGL() = default;
	RendererGL::~RendererGL() = default;

	void RendererGL::init()
	{
		// Initializes GLEW
		GLenum init = glewInit();
		if (init != GLEW_OK)
		{
			LYS_CRITICAL("GLEW failed to initialize correctly.", glGetError());
		}
		
		glEnable(GL_DEPTH_TEST);

		LYS_INFO("Renderer: ", glGetString(GL_RENDERER));
		LYS_INFO("OpenGL version: ", glGetString(GL_VERSION));

		int numAttributes;
		glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &numAttributes);
		LYS_INFO("Maximum number of vertex attributes supported: ", numAttributes);
	}

	void RendererGL::update_viewport(const int width, const int height) const { glViewport(0, 0, width, height); }

	void RendererGL::clear() const
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
} // namespace Lys
