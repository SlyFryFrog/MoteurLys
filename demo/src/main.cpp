#include <chrono>
#include <vector>
#include "LilyPad/core/physics/rigid_body_2d.hpp"
#include "LilyPad/core/physics/world.hpp"
#include "LilyPad/core/rendering/texture.hpp"
#include "LilyPad/core/rendering/vertex.hpp"
#include "LilyPad/core/rendering/window.hpp"
#include "LilyPad/core/shaders/shader_program.hpp"
#include "LilyPad/debug/logging.hpp"

using namespace LilyPad;

World world;

void update(const std::vector<RigidBody2D> &bodies, float delta)
{
	for (RigidBody2D body : bodies)
	{
		world.apply_gravity(body);
		body.physics_process(delta);
	}
}

int main()
{
	Window window;
	window.set_title("LilyPad Engine Demo");
	window.set_dimensions(500, 500);

	window.initialize();

	ShaderProgram shaders("Vertex.glsl", "Fragment.glsl");

	shaders.create_shader_program();

	// Render loop
	while (!window.is_done())
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



		glfwSwapBuffers(window.window);
		glfwPollEvents();
	}

	return 0;
}