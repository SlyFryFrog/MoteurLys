#include "fps.hpp"

#ifdef OpenGL
#include <GL/glew.h>
#endif
#include <GLFW/glfw3.h>

namespace Lys
{
	FPS *FPS::_singleton = nullptr;

	void FPS::update()
	{
		lastFrameTime = currentFrameTime;
		currentFrameTime = glfwGetTime();
	}

	double FPS::get_delta() const { return (currentFrameTime - lastFrameTime); }

	FPS *FPS::get_singleton()
	{
		if (!_singleton)
		{
			_singleton = new FPS();
		}

		return _singleton;
	}

	FPS::FPS() : frameRate(0.0)
	{
		lastFrameTime = glfwGetTime();
		currentFrameTime = lastFrameTime;
	}

	FPS::~FPS() { delete _singleton; }
} // namespace Lys
