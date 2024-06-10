#include <vector>
#include <chrono>
#include "core/rendering/window.hpp"
#include "core/physics/rigid_body_2d.hpp"

using namespace LilyPad;

void update(const std::vector<RigidBody2D> &bodies, float delta) 
{
	for (RigidBody2D body : bodies)
	{
		body.physics_process(delta);
	}
}

int main()
{
	Window window;
	window.set_title("LilyPad Engine Demo");
	window.set_dimensions(500, 500);

	window.initialize();

	std::vector<RigidBody2D> bodies;
    auto previousTime = std::chrono::steady_clock::now();

	// Render loop
	while (!window.is_done())
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Calc delta
		const auto currentTime = std::chrono::steady_clock::now();
		std::chrono::duration<float> elapsedTime = currentTime - previousTime;
		float delta = elapsedTime.count(); // deltaTime in seconds

		update(bodies, delta);

		glfwSwapBuffers(window.window);
		glfwPollEvents();
	}

	return 0;
}