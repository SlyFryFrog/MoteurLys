#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "LilyPad/core/math/vector3.hpp"
#include "LilyPad/core/physics/rigid_body_2d.hpp"
#include "LilyPad/core/physics/world.hpp"
#include "LilyPad/core/utils/paths.hpp"
#include "LilyPad/debug/logging.hpp"
#include "LilyPad/renderer/OpenGL/shaders/shader_program.hpp"
#include "LilyPad/renderer/OpenGL/texture.hpp"
#include "LilyPad/renderer/OpenGL/vertex.hpp"
#include "LilyPad/renderer/OpenGL/window.hpp"
#include <cstddef>

using namespace LilyPad;

void processInput(GLFWwindow *window);

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
float deltaTime = 0.0f; // Time between current frame and last frame
float lastFrame = 0.0f; // Time of last frame
unsigned int texture1;

int main()
{
	const std::string relativePath = get_root_directory();
	Window window = Window(SCR_WIDTH, SCR_HEIGHT);
	window.set_title("Demo");
	window.initialize();

	ShaderProgram ourShader(std::string(relativePath + "/rsc/shaders/"));
	ourShader.set_shader_code("Vertex.glsl", "Fragment.glsl");
	ourShader.create_shader_program();

	// set up vertex data (and buffer(s)) and configure vertex attributes
	Vertices<float> vertices(
		{{{-0.5f, -0.5f, -0.5f}, {0.0f, 0.0f}}, 
		{{0.5f, -0.5f, -0.5f}, {1.0f, 0.0f}}, 
		{{0.5f, 0.5f, -0.5f}, {1.0f, 1.0f}},
	  	{{0.5f, 0.5f, -0.5f}, {1.0f, 1.0f}}, 
		{{-0.5f, 0.5f, -0.5f}, {0.0f, 1.0f}}, 
		{{-0.5f, -0.5f, -0.5f}, {0.0f, 0.0f}},

		{{-0.5f, -0.5f, 0.5f}, {0.0f, 0.0f}}, 
		{{0.5f, -0.5f, 0.5f}, {1.0f, 0.0f}}, 
		{{0.5f, 0.5f, 0.5f}, {1.0f, 1.0f}},
	  	{{0.5f, 0.5f, 0.5f}, {1.0f, 1.0f}}, 
		{{-0.5f, 0.5f, 0.5f}, {0.0f, 1.0f}}, 
		{{-0.5f, -0.5f, 0.5f}, {0.0f, 0.0f}},

	  	{{-0.5f, 0.5f, 0.5f}, {1.0f, 0.0f}}, 
		{{-0.5f, 0.5f, -0.5f}, {1.0f, 1.0f}}, 
		{{-0.5f, -0.5f, -0.5f}, {0.0f, 1.0f}},
	  	{{-0.5f, -0.5f, -0.5f}, {0.0f, 1.0f}}, 
		{{-0.5f, -0.5f, 0.5f}, {0.0f, 0.0f}}, 
		{{-0.5f, 0.5f, 0.5f}, {1.0f, 0.0f}},

		{{0.5f, 0.5f, 0.5f}, {1.0f, 0.0f}}, 
		{{0.5f, 0.5f, -0.5f}, {1.0f, 1.0f}}, 
		{{0.5f, -0.5f, -0.5f}, {0.0f, 1.0f}},
		{{0.5f, -0.5f, -0.5f}, {0.0f, 1.0f}}, 
		{{0.5f, -0.5f, 0.5f}, {0.0f, 0.0f}}, 
		{{0.5f, 0.5f, 0.5f}, {1.0f, 0.0f}},

		{{-0.5f, -0.5f, -0.5f}, {0.0f, 1.0f}}, 
		{{0.5f, -0.5f, -0.5f}, {1.0f, 1.0f}}, 
		{{0.5f, -0.5f, 0.5f}, {1.0f, 0.0f}},
		{{0.5f, -0.5f, 0.5f}, {1.0f, 0.0f}}, 
		{{-0.5f, -0.5f, 0.5f}, {0.0f, 0.0f}}, 
		{{-0.5f, -0.5f, -0.5f}, {0.0f, 1.0f}},

		{{-0.5f, 0.5f, -0.5f}, {0.0f, 1.0f}}, 
		{{0.5f, 0.5f, -0.5f}, {1.0f, 1.0f}},
		{{0.5f, 0.5f, 0.5f}, {1.0f, 0.0f}},
	   	{{0.5f, 0.5f, 0.5f}, {1.0f, 0.0f}},
		{{-0.5f, 0.5f, 0.5f}, {0.0f, 0.0f}},
		{{-0.5f, 0.5f, -0.5f}, {0.0f, 1.0f}}}
	);

	Vector3 cubePositions[] = {{0.0f, 0.0f, 0.0f},	   {2.0f, 5.0f, -15.0f}, {-1.5f, -2.2f, -2.5f},
							   {-3.8f, -2.0f, -12.3f}, {2.4f, -0.4f, -3.5f}, {-1.7f, 3.0f, -7.5f},
							   {1.3f, -2.0f, -2.5f},   {1.5f, 2.0f, -2.5f},	 {1.5f, 0.2f, -1.5f},
							   {-1.3f, 1.0f, -1.5f}};

	unsigned int VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	vertices.bind_buffer(VBO);
	vertices.set_attributes();
	// glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// glBufferData(GL_ARRAY_BUFFER, vertices.get_vector().size() * sizeof(float), vertices.get_data(), GL_STATIC_DRAW);

	// // position attribute
	// glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
	// glEnableVertexAttribArray(0);

	// // texture coord attribute
	// glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(3 * sizeof(float)));
	// glEnableVertexAttribArray(1);
	// glBindVertexArray(0);
	glEnable(GL_DEPTH_TEST);

	Texture texture(relativePath + "/rsc/textures/");
	texture1 = texture.generate_texture("R.png");


	ourShader.use();
	ourShader.set_uniform("uTexture", 0);

	glm::mat4 view;
	view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

	while (!window.is_done())
	{
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		processInput(window.window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// bind textures on corresponding texture units
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture1);

		glm::mat4 projection;
		projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

		ourShader.use();
		glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
		ourShader.set_uniform("uView", view);
		ourShader.set_uniform("uProjection", projection);

		glBindVertexArray(VAO);
		for (int i = 0; i < 10; i++)
		{
			glm::mat4 model = glm::mat4(1.0f);
			model = glm::translate(model, glm::vec3(cubePositions[i].x, cubePositions[i].y, cubePositions[i].z));
			float angle = (float)glfwGetTime() * glm::radians(50.0f) * pow(-1, i);
			model = glm::rotate(model, angle, glm::vec3(1.0f, 0.3f, 0.5f));
			ourShader.set_uniform("uModel", model);

			glDrawArrays(GL_TRIANGLES, 0, 36);
		}

		glfwSwapBuffers(window.window);
		glfwPollEvents();
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	glfwTerminate();
	return 0;
}

void processInput(GLFWwindow *window)
{
	float cameraSpeed = 2.5f * deltaTime;
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		cameraPos += cameraSpeed * cameraFront;
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		cameraPos -= cameraSpeed * cameraFront;
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
}