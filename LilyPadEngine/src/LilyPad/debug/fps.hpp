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

		/**
		 * @brief Gets the delta between frames.
		 *
		 * @return double Time between frames in terms of seconds.
		 */
		double get_delta();

	private:
		// Time points to manage timing
		double lastFrameTime;
		double currentFrameTime;
		double frameRate;
	};
} // namespace LilyPad
