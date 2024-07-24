#pragma once

#include <chrono>

namespace LilyPad
{
	class FPS
	{
	public:
		float frameRate;

		FPS();

		// Update the frame rate
		void update();

	private:
		// Time points to manage timing
		std::chrono::steady_clock::time_point lastFrameTime;
		std::chrono::steady_clock::time_point currentFrameTime;
	};
} // namespace LilyPad
