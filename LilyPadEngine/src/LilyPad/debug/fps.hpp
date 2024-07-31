#pragma once

#include <chrono>

namespace LilyPad
{
	class FPS
	{
	public:

		FPS();

		// Update the frame rate
		void update();

		float get_delta();
	private:
		// Time points to manage timing
		float lastFrameTime;
		float currentFrameTime;
		float frameRate;
	};
} // namespace LilyPad
