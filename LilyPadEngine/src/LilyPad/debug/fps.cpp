#include "fps.hpp"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace LilyPad
{
	FPS *FPS::_singleton = nullptr;
	
	void FPS::update()
	{
		lastFrameTime = currentFrameTime;
		currentFrameTime = glfwGetTime();
	}

	double FPS::get_delta() { return (currentFrameTime - lastFrameTime); }

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

	FPS::~FPS()
	{
		delete _singleton;
	}
} // namespace LilyPad
