#pragma once

#include <filesystem>
#include <glm/glm.hpp>
#include <string>

namespace LilyPad
{
	class Shader
	{
	public:
		Shader(const std::string &path, unsigned int type);

		bool is_updated();
		void update();

		static std::string read_file(const std::string &path);
		std::string read_file();

	private:
		std::string _shaderCode;
		std::string _path;
		std::filesystem::file_time_type _lastTime;
	};

	class ShaderProgram
	{
	public:
		unsigned int program; // The OpenGL ID of the shader program.

		ShaderProgram(const std::string &path, const std::string &vertex, const std::string &fragment);
		~ShaderProgram();

		/**
		 * @brief Creates and links the shader program from the previously loaded vertex and fragment shaders.
		 */
		void create_shader_program();

		/**
		 * @brief Assigns the shader program to be used by OpenGL for rendering.
		 */
		void use() const;

		int get_attribute_location(const std::string &name);


		void set_uniform(const std::string &name, const int value) const;
		void set_uniform(const std::string &name, const float value) const;
		void set_uniform(const std::string &name, const glm::mat3 &trans) const;
		void set_uniform(const std::string &name, const glm::mat4 &trans) const;

		/**
		 * @brief If the last write time has changed, it gets and applies the new shader code to the program.
		 */
		void reload();

	private:
		/**
		 * @brief Checks the compilation status of a shader and logs any errors.
		 *
		 * @param shader The ID of the shader to check.
		 * @param type The type of the shader (GL_VERTEX_SHADER or GL_FRAGMENT_SHADER).
		 * @return int representing the sucess of the compilation.
		 */
		static int check_compile_errors(unsigned int shader, unsigned int type);

		Shader _vShader;
		Shader _fShader;
		std::string _path;

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