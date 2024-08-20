#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <lys.hpp>
#include <memory>
#include "camera.hpp"
#include "level/generation.hpp"

using namespace Lys;

void mouse_callback(GLFWwindow *window, double xpos, double ypos);
void process_input();
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

double delta = 0.0;		// Time between current frame and last frame
float lastFrame = 0.0f; // Time of last frame
ShaderProgram ourShader("/home/marcus/dev/MoteurLys/demo/rsc/shaders/", "Vertex.glsl", "Fragment.glsl");
auto camera = std::make_shared<Camera>();
Label label;
Input *inputs = Input::get_singleton();
void printMatrix(const Matrix4 &mat)
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			std::cout << mat[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
int main()
{
	Sprite2D sprite;
	sprite.position = {0, 10};

	std::vector<uint8_t> pixels(1000 * 1000 * 1);
	const float GRID_SIZE = 400;

	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < 1000; j++)
		{
			int index = (j * 1000 + i) * 1;
			float val = 0.0f;

			float freq = 1.0f;
			float amp = 1.0f;

			for (int k = 0; k < 12; k++)
			{
				val += perlin(i * freq / GRID_SIZE, j * freq / GRID_SIZE) * amp;
				freq *= 2.0f;
				amp /= 2.0f;
			}

			// Adds contrast
			val *= 1.2f;

			if (val > 1.0f)
				val = 1.0f;
			else if (val < -1.0f)
				val = -1.0f;

			uint8_t color = (uint8_t)((val + 1.0f) * 0.5f * 255);
			pixels[index] = color;
			pixels[index + 3] = 255;
		}
	}

	sprite.image.set_data(1000, 1000, false, ImageFormat::R8, pixels);

	camera->_ready();
	camera->set_name("camera");
	const std::string relativePath = get_root_directory();
	Window window = Window(SCR_WIDTH, SCR_HEIGHT);
	window.set_title("Demo");
	window.initialize();

	glfwSetInputMode(window.window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPosCallback(window.window, mouse_callback);
	glEnable(GL_DEPTH_TEST);

	ourShader.create_shader_program();

	// set up vertex data (and buffer(s)) and configure vertex attributes
	Vertices<float> vertices({{{-0.5f, -0.5f, -0.5f}, {0.0f, 0.0f}}, {{0.5f, -0.5f, -0.5f}, {1.0f, 0.0f}},
							  {{0.5f, 0.5f, -0.5f}, {1.0f, 1.0f}},	 {{0.5f, 0.5f, -0.5f}, {1.0f, 1.0f}},
							  {{-0.5f, 0.5f, -0.5f}, {0.0f, 1.0f}},	 {{-0.5f, -0.5f, -0.5f}, {0.0f, 0.0f}},

							  {{-0.5f, -0.5f, 0.5f}, {0.0f, 0.0f}},	 {{0.5f, -0.5f, 0.5f}, {1.0f, 0.0f}},
							  {{0.5f, 0.5f, 0.5f}, {1.0f, 1.0f}},	 {{0.5f, 0.5f, 0.5f}, {1.0f, 1.0f}},
							  {{-0.5f, 0.5f, 0.5f}, {0.0f, 1.0f}},	 {{-0.5f, -0.5f, 0.5f}, {0.0f, 0.0f}},

							  {{-0.5f, 0.5f, 0.5f}, {1.0f, 0.0f}},	 {{-0.5f, 0.5f, -0.5f}, {1.0f, 1.0f}},
							  {{-0.5f, -0.5f, -0.5f}, {0.0f, 1.0f}}, {{-0.5f, -0.5f, -0.5f}, {0.0f, 1.0f}},
							  {{-0.5f, -0.5f, 0.5f}, {0.0f, 0.0f}},	 {{-0.5f, 0.5f, 0.5f}, {1.0f, 0.0f}},

							  {{0.5f, 0.5f, 0.5f}, {1.0f, 0.0f}},	 {{0.5f, 0.5f, -0.5f}, {1.0f, 1.0f}},
							  {{0.5f, -0.5f, -0.5f}, {0.0f, 1.0f}},	 {{0.5f, -0.5f, -0.5f}, {0.0f, 1.0f}},
							  {{0.5f, -0.5f, 0.5f}, {0.0f, 0.0f}},	 {{0.5f, 0.5f, 0.5f}, {1.0f, 0.0f}},

							  {{-0.5f, -0.5f, -0.5f}, {0.0f, 1.0f}}, {{0.5f, -0.5f, -0.5f}, {1.0f, 1.0f}},
							  {{0.5f, -0.5f, 0.5f}, {1.0f, 0.0f}},	 {{0.5f, -0.5f, 0.5f}, {1.0f, 0.0f}},
							  {{-0.5f, -0.5f, 0.5f}, {0.0f, 0.0f}},	 {{-0.5f, -0.5f, -0.5f}, {0.0f, 1.0f}},

							  {{-0.5f, 0.5f, -0.5f}, {0.0f, 1.0f}},	 {{0.5f, 0.5f, -0.5f}, {1.0f, 1.0f}},
							  {{0.5f, 0.5f, 0.5f}, {1.0f, 0.0f}},	 {{0.5f, 0.5f, 0.5f}, {1.0f, 0.0f}},
							  {{-0.5f, 0.5f, 0.5f}, {0.0f, 0.0f}},	 {{-0.5f, 0.5f, -0.5f}, {0.0f, 1.0f}}});

	Vector3 cubePositions[] = {{0.0f, 0.0f, 0.0f},	   {2.0f, 5.0f, -15.0f}, {-1.5f, -2.2f, -2.5f},
							   {-3.8f, -2.0f, -12.3f}, {2.4f, -0.4f, -3.5f}, {-1.7f, 3.0f, -7.5f},
							   {1.3f, -2.0f, -2.5f},   {1.5f, 2.0f, -2.5f},	 {1.5f, 0.2f, -1.5f},
							   {-1.3f, 1.0f, -1.5f}};

	VertexArray vao;
	VertexBuffer vbo;

	Texture texture(relativePath + "/rsc/textures/");

	texture.id = texture.load_data(sprite.image);

	ourShader.use();
	ourShader.set_uniform("uTexture", texture.id);

	Vertices<float> vertices2({{{-1.0f, 1.0f, 0.0f}, {0.0f, 1.0f}},
							   {{-1.0f, -1.0f, 0.0f}, {0.0f, 0.0f}},
							   {{1.0f, -1.0f, 0.0f}, {1.0f, 0.0f}},
							   {{-1.0f, 1.0f, 0.0f}, {0.0f, 1.0f}},
							   {{1.0f, -1.0f, 0.0f}, {1.0f, 0.0f}},
							   {{1.0f, 1.0f, 0.0f}, {1.0f, 1.0f}}});

	vao.bind();
	vbo.set_data(vertices);
	vertices.set_attributes();

	while (!window.is_done())
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		LYS_FPS_UPDATE();
		delta = LYS_DELTA();

		// bind textures on corresponding texture units
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture.id);

		glm::mat4 projection =
			glm::perspective(glm::radians(camera->zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);

		ourShader.use();
		ourShader.set_uniform("uView", {camera->get_view()});
		ourShader.set_uniform("uProjection", projection);

		vao.bind();

		for (int i = 0; i < 10; i++)
		{
			glm::mat4 model = glm::mat4(1.0f);
			model = glm::translate(model, glm::vec3(cubePositions[i]));
			ourShader.set_uniform("uModel", model);

			glDrawArrays(GL_TRIANGLES, 0, 36);
		}

		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0, 0, 0));
		ourShader.set_uniform("uModel", model);

		glDrawArrays(GL_TRIANGLES, 0, 6);


		process_input();
		camera->_process(delta);

		window.poll_events();
		window.swap_frame_buffer();
		vao.unbind();
	}

	Window::terminate();

	return 0;
}

void process_input()
{
	std::vector<InputHandler> queueForRemoval;

	// Processes each event and modifies their repeat status
	for (auto &event : inputs->get_keys_events())
	{
		camera->_process_input(event);

		if (event.is_just_pressed())
			event.set_repeat(true);
		else if (event.is_just_released())
			event.set_repeat(true);
		else if (event.is_released())
			queueForRemoval.push_back(event);
	}

	// Removes each event that has been released for more than a frame
	for (auto &event : queueForRemoval)
	{
		inputs->remove_key_event(event);
	}
}

void mouse_callback(GLFWwindow *window, double xposIn, double yposIn)
{
	const auto xpos = static_cast<float>(xposIn);
	const auto ypos = static_cast<float>(yposIn);

	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xOffset = xpos - lastX;
	float yOffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

	lastX = xpos;
	lastY = ypos;

	camera->process_mouse_movement(xOffset, yOffset);
}