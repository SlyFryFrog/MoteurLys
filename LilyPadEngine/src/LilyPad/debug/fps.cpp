#include "fps.hpp"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace LilyPad
{
	FPS::FPS() : frameRate(0.0f)
	{
		lastFrameTime = glfwGetTime();
		currentFrameTime = lastFrameTime;
	}

	void FPS::update()
	{
		currentFrameTime = glfwGetTime();
		lastFrameTime = currentFrameTime;
	}

	float FPS::get_delta()
	{
		return glfwGetTime() - lastFrameTime;
	}
} // namespace LilyPad
