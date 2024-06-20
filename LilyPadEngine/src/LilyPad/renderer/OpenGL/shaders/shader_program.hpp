#pragma once

#include <glm/glm.hpp>
#include <string>

namespace LilyPad
{
	/**
	 * @brief A class representing a shader program in OpenGL.
	 *
	 * This class encapsulates the functionality related to loading,
	 * compiling, and managing vertex and fragment shaders in an OpenGL
	 * shader program.
	 */
	class ShaderProgram
	{
	public:
		unsigned int program; // The OpenGL ID of the shader program.

		ShaderProgram();

		ShaderProgram(const std::string &path);

		/**
		 * @brief Destroy the Shader Program object and removes the program from OpenGL.
		 */
		~ShaderProgram();

		void set_shader_code(const std::string &vertexPath, const std::string &fragmentPath);

		/**
		 * @brief Checks the compilation status of a shader and logs any errors.
		 *
		 * @param shader The ID of the shader to check.
		 * @param type The type of the shader (GL_VERTEX_SHADER or GL_FRAGMENT_SHADER).
		 * @return int representing the sucess of the compilation.
		 */
		static int check_compile_errors(unsigned int shader, unsigned int type);

		/**
		 * @brief Creates and links the shader program from the provided vertex and fragment shader source codes.
		 *
		 * @param vertexShader The source code of the vertex shader.
		 * @param fragmentShader The source code of the fragment shader.
		 */
		void create_shader_program(const std::string &vertexShader, const std::string &fragmentShader);

		/**
		 * @brief Creates and links the shader program from the previously loaded vertex and fragment shaders.
		 */
		void create_shader_program();

		/**
		 * @brief Assigns the shader program to be used by OpenGL for rendering.
		 */
		void use() const;

		/**
		 * @brief Set the int variable.
		 *
		 * @param name Uniform variable name.
		 * @param value Value to set the uniform variable to.
		 */
		void set_uniform(const std::string &name, const int value) const;

		/**
		 * @brief Set the float variable.
		 *
		 * @param name Uniform variable name.
		 * @param value Value to set the uniform variable to.
		 */
		void set_uniform(const std::string &name, const float value) const;

		/**
		 * @brief Set the mat3 variable.
		 *
		 * @param name Uniform variable name.
		 * @param value Value to set the uniform variable to.
		 */
		void set_uniform(const std::string &name, const glm::mat3 &trans) const;

		/**
		 * @brief Set the mat4 variable.
		 *
		 * @param name Uniform variable name.
		 * @param value Value to set the uniform variable to.
		 */
		void set_uniform(const std::string &name, const glm::mat4 &trans) const;

	private:
		std::string _vShaderCode; // String containing the source code of the vertex shader.
		std::string _fShaderCode; // String containing the source code of the fragment shader.
		std::string _path;

		/**
		 * @brief Reads the file at the provided path and returns the
		 * parsed contents as a std::string.
		 *
		 * @param file File name of the shader script. Needs to be added to CMakeLists in order to be correctly
		 * included. Adds prefix "shaders/" to the path.
		 * @return std::string Contents of the shader file; the code in the glsl file.
		 */
		std::string read_file(const std::string &file);

		/**
		 * @brief Compiles a shader from the provided source code.
		 *
		 * @param source The source code of the shader.
		 * @param type The type of the shader (GL_VERTEX_SHADER or GL_FRAGMENT_SHADER).
		 * @return unsigned int The OpenGL ID of the compiled shader.
		 */
		static unsigned int compile_shader(const std::string &source, unsigned int type);
	};
} // namespace LilyPad