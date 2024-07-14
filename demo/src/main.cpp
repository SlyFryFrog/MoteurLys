#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "LilyPad/core/math/vector3.hpp"
#include "LilyPad/core/utils/paths.hpp"
#include "LilyPad/debug/logging.hpp"
#include "LilyPad/renderer/OpenGL/binding/bind.hpp"
#include "LilyPad/renderer/OpenGL/shaders/shader_program.hpp"
#include "LilyPad/renderer/OpenGL/texture.hpp"
#include "LilyPad/renderer/OpenGL/vertex.hpp"
#include "LilyPad/renderer/OpenGL/window.hpp"
#include "LilyPad/scene/nodes/3d/camera_3d.hpp"

using namespace LilyPad;

void process_input(GLFWwindow *window);
void framebuffer_size_callback(GLFWwindow *window, int width, int height);

fp_type deltaTime = 0.0f; // Time between current frame and last frame
fp_type lastFrame = 0.0f; // Time of last frame
ShaderProgram ourShader("/home/marcus/dev/LilyPadEngine/demo/rsc/shaders/", "Vertex.glsl", "Fragment.glsl");
Camera3D camera;

int main()
{
	const unsigned int SCR_WIDTH = 800;
	const unsigned int SCR_HEIGHT = 600;
	const std::string relativePath = get_root_directory();
	Window window = Window(SCR_WIDTH, SCR_HEIGHT);
	window.set_title("Demo");
	window.initialize();

	ourShader.create_shader_program();

	// set up vertex data (and buffer(s)) and configure vertex attributes
	Vertices<fp_type> vertices({{{-0.5f, -0.5f, -0.5f}, {0.0f, 0.0f}}, {{0.5f, -0.5f, -0.5f}, {1.0f, 0.0f}},
								{{0.5f, 0.5f, -0.5f}, {1.0f, 1.0f}},   {{0.5f, 0.5f, -0.5f}, {1.0f, 1.0f}},
								{{-0.5f, 0.5f, -0.5f}, {0.0f, 1.0f}},  {{-0.5f, -0.5f, -0.5f}, {0.0f, 0.0f}},

								{{-0.5f, -0.5f, 0.5f}, {0.0f, 0.0f}},  {{0.5f, -0.5f, 0.5f}, {1.0f, 0.0f}},
								{{0.5f, 0.5f, 0.5f}, {1.0f, 1.0f}},	   {{0.5f, 0.5f, 0.5f}, {1.0f, 1.0f}},
								{{-0.5f, 0.5f, 0.5f}, {0.0f, 1.0f}},   {{-0.5f, -0.5f, 0.5f}, {0.0f, 0.0f}},

								{{-0.5f, 0.5f, 0.5f}, {1.0f, 0.0f}},   {{-0.5f, 0.5f, -0.5f}, {1.0f, 1.0f}},
								{{-0.5f, -0.5f, -0.5f}, {0.0f, 1.0f}}, {{-0.5f, -0.5f, -0.5f}, {0.0f, 1.0f}},
								{{-0.5f, -0.5f, 0.5f}, {0.0f, 0.0f}},  {{-0.5f, 0.5f, 0.5f}, {1.0f, 0.0f}},

								{{0.5f, 0.5f, 0.5f}, {1.0f, 0.0f}},	   {{0.5f, 0.5f, -0.5f}, {1.0f, 1.0f}},
								{{0.5f, -0.5f, -0.5f}, {0.0f, 1.0f}},  {{0.5f, -0.5f, -0.5f}, {0.0f, 1.0f}},
								{{0.5f, -0.5f, 0.5f}, {0.0f, 0.0f}},   {{0.5f, 0.5f, 0.5f}, {1.0f, 0.0f}},

								{{-0.5f, -0.5f, -0.5f}, {0.0f, 1.0f}}, {{0.5f, -0.5f, -0.5f}, {1.0f, 1.0f}},
								{{0.5f, -0.5f, 0.5f}, {1.0f, 0.0f}},   {{0.5f, -0.5f, 0.5f}, {1.0f, 0.0f}},
								{{-0.5f, -0.5f, 0.5f}, {0.0f, 0.0f}},  {{-0.5f, -0.5f, -0.5f}, {0.0f, 1.0f}},

								{{-0.5f, 0.5f, -0.5f}, {0.0f, 1.0f}},  {{0.5f, 0.5f, -0.5f}, {1.0f, 1.0f}},
								{{0.5f, 0.5f, 0.5f}, {1.0f, 0.0f}},	   {{0.5f, 0.5f, 0.5f}, {1.0f, 0.0f}},
								{{-0.5f, 0.5f, 0.5f}, {0.0f, 0.0f}},   {{-0.5f, 0.5f, -0.5f}, {0.0f, 1.0f}}});

	Vector3 cubePositions[] = {{0.0f, 0.0f, 0.0f},	   {2.0f, 5.0f, -15.0f}, {-1.5f, -2.2f, -2.5f},
							   {-3.8f, -2.0f, -12.3f}, {2.4f, -0.4f, -3.5f}, {-1.7f, 3.0f, -7.5f},
							   {1.3f, -2.0f, -2.5f},   {1.5f, 2.0f, -2.5f},	 {1.5f, 0.2f, -1.5f},
							   {-1.3f, 1.0f, -1.5f}};

	camera.position = {0.0f, 0.0f, 10.0f};
	camera.up = {0.0f, 1.0f, 0.0f};

	Position3 point = {-1.0f, 0.0f, -1.0f};
	camera.look_at(point);
	
	Bind bind;
	bind.bind_vertices(vertices);
	vertices.set_attributes();
	std::cout << vertices << "\n";
	glEnable(GL_DEPTH_TEST);

	Texture texture(relativePath + "/rsc/textures/");
	texture.id = texture.generate_texture("frog.png");

	ourShader.use();
	ourShader.set_uniform("uTexture", texture.id);

	glfwSetInputMode(window.window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	// glfwSetCursorPosCallback(window.window, mouse_callback);

	while (!window.is_done())
	{
		fp_type currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		process_input(window.window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// bind textures on corresponding texture units
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture.id);

		glm::mat4 projection;
		projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

		ourShader.use();
		ourShader.set_uniform("uView", camera.viewMatrix);
		ourShader.set_uniform("uProjection", projection);

		bind.bind_vertex_array();
		for (int i = 0; i < 10; i++)
		{
			glm::mat4 model = glm::mat4(1.0f);
			model = glm::translate(model, glm::vec3(cubePositions[i].x, cubePositions[i].y, cubePositions[i].z));
			fp_type angle = (fp_type)glfwGetTime() * glm::radians(50.0f) * pow(-1, i);
			model = glm::rotate(model, angle, glm::vec3(1.0f, 0.3f, 0.5f));
			ourShader.set_uniform("uModel", model);

			glDrawArrays(GL_TRIANGLES, 0, 36);
		}

		glfwSwapBuffers(window.window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

void process_input(GLFWwindow *window)
{
	fp_type cameraSpeed = 2.5f * deltaTime;

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera.position += cameraSpeed * camera.forward;
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera.position -= cameraSpeed * camera.forward;
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera.position -= Vector3::normalize(Vector3::cross(camera.forward, camera.up)) * cameraSpeed;
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera.position += Vector3::normalize(Vector3::cross(camera.forward, camera.up)) * cameraSpeed;
	if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
		ourShader.reload();
}