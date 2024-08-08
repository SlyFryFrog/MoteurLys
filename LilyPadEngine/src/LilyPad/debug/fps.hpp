#pragma once

#include <chrono>

/**
 * @brief Returns the current delta in seconds.
 * 
 * @return delta Delta time in seconds.
 */
#define LILYPAD_DELTA() LilyPad::FPS::get_singleton()->get_delta();

/**
 * @brief Recalculates delta between the current and previous frame.
 *
 * This should be called once per frame to ensure accurate timing information.
 */
#define LILYPAD_FPS_UPDATE() LilyPad::FPS::get_singleton()->update();

namespace LilyPad
{
	class FPS
	{
		static FPS *_singleton;

	public:
		static FPS *get_singleton();

		// Update the frame rate
		void update();

		/**
		 * @brief Gets the delta between frames.
		 *
		 * @return double Time between frames in terms of seconds.
		 */
		double get_delta() const;

	private:
		FPS();
		~FPS();

		// Time points to manage timing
		double lastFrameTime;
		double currentFrameTime;
		double frameRate;
	};
} // namespace LilyPad
