#pragma once

#include <filesystem>
#include <glm/glm.hpp>
#include <string>
#include <vector>
#include "Lys/core/io/file.hpp"
#include "Lys/core/math/matrix4.hpp"

namespace Lys
{
	class Shader : public File
	{
	public:
		Shader(const std::string &path, unsigned int type);

		void update() override;

	private:
		std::string _shaderCode;
	};

	class ShaderProgram
	{
	public:
		unsigned int id; // The OpenGL ID of the shader program.
		std::string name;

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

		[[nodiscard]] int get_attribute_location(const std::string &name) const;

		void set_uniform(const std::string &name, int value) const;
		void set_uniform(const std::string &name, unsigned int value) const;
		void set_uniform(const std::string &name, float value) const;
		void set_uniform(const std::string &name, const glm::mat3 &trans) const;
		void set_uniform(const std::string &name, const glm::mat4 &trans) const;
		void set_uniform(const std::string &name, const Matrix4 &trans) const;

		/**
		 * @brief If the last write time has changed, it gets and applies the new shader code to the program.
		 */
		void reload();

	private:
		Shader _vShader;
		Shader _fShader;
		std::string _path;

		/**
		 * @brief Checks the compilation status of a shader and logs any errors.
		 *
		 * @param shader The ID of the shader to check.
		 * @param type The type of the shader (GL_VERTEX_SHADER or GL_FRAGMENT_SHADER).
		 * @return int representing the sucess of the compilation.
		 */
		static int check_compile_errors(unsigned int shader, unsigned int type);

		/**
		 * @brief Compiles a shader from the provided source code.
		 *
		 * @param source The source code of the shader.
		 * @param type The type of the shader (GL_VERTEX_SHADER or GL_FRAGMENT_SHADER).
		 * @return unsigned int The OpenGL ID of the compiled shader.
		 */
		static unsigned int compile_shader(const std::string &source, unsigned int type);
	};
} // namespace Lys