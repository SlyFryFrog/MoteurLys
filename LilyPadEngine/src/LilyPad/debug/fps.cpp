#include "fps.hpp"

namespace LilyPad
{
	FPS::FPS() : frameRate(0.0f)
	{
		lastFrameTime = std::chrono::steady_clock::now();
		currentFrameTime = lastFrameTime;
	}

	void FPS::update()
	{
		currentFrameTime = std::chrono::steady_clock::now();
		std::chrono::duration<float> elapsed = currentFrameTime - lastFrameTime;
		frameRate = 1.0f / elapsed.count();
		lastFrameTime = currentFrameTime;
	}
} // namespace LilyPad
