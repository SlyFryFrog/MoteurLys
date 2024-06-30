#include "LilyPad/renderer/OpenGL/shaders/shader_program.hpp"

#include <GL/glew.h>
#include <fstream>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <sstream>
#include "LilyPad/debug/logging.hpp"


namespace LilyPad
{
	std::string ShaderProgram::read_file(const std::string &file)
	{
		std::ifstream shaderFile;
		std::string code;
		shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

		try
		{
			shaderFile.open(_path + file);
			std::stringstream shaderStream;
			shaderStream << shaderFile.rdbuf();
			shaderFile.close();

			code = shaderStream.str();
		}
		catch (std::ifstream::failure &e)
		{
			const std::string path = _path + file;
			LILYPAD_ERROR("SHADER::FILE_NOT_SUCCESSFULLY_READY: ", path, " ", e.what());
		}

		return code;
	}

	void ShaderProgram::set_shader_code(const std::string &vertexPath, const std::string &fragmentPath)
	{
		_vShaderCode = read_file(vertexPath);
		_fShaderCode = read_file(fragmentPath);
	}

	unsigned int ShaderProgram::compile_shader(const std::string &source, const unsigned int type)
	{
		const unsigned int shaderID = glCreateShader(type);
		const char *src = source.c_str();
		glShaderSource(shaderID, 1, &src, nullptr);
		glCompileShader(shaderID);

		// Checks the compilation status for any potential errors
		if (!check_compile_errors(shaderID, type))
		{
			glDeleteShader(shaderID);
			return 0;
		}

		return shaderID;
	}

	ShaderProgram::ShaderProgram() = default;

	ShaderProgram::ShaderProgram(const std::string &path) : _path(path) {}

	ShaderProgram::~ShaderProgram() { glDeleteProgram(program); }

	int ShaderProgram::check_compile_errors(const unsigned int shader, const unsigned int type)
	{
		int success;
		char infoLog[1024];

		if (type != GL_PROGRAM)
		{
			glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
			if (!success)
			{
				glGetShaderInfoLog(shader, 1024, nullptr, infoLog);
				LILYPAD_ERROR("ERROR::SHADER_COMPILATION_ERROR of type: ", type, "\n", infoLog,
							  "-- --------------------------------------------------- --");
			}
		}
		else
		{
			glGetProgramiv(shader, GL_LINK_STATUS, &success);
			if (!success)
			{
				glGetProgramInfoLog(shader, 1024, nullptr, infoLog);
				LILYPAD_ERROR("ERROR::PROGRAM_LINKING_ERROR of type: ", type, "\n", infoLog,
							  "-- --------------------------------------------------- --");
			}
		}

		return success;
	}

	void ShaderProgram::create_shader_program(const std::string &vertexShader, const std::string &fragmentShader)
	{
		program = glCreateProgram();
		unsigned int vertex = compile_shader(vertexShader, GL_VERTEX_SHADER);
		LILYPAD_DEBUG("Finished compiling vertex shader.");
		unsigned int fragment = compile_shader(fragmentShader, GL_FRAGMENT_SHADER);
		LILYPAD_DEBUG("Finished compiling fragment shader.");

		// Loads the shaders to the program
		glAttachShader(program, vertex);
		glAttachShader(program, fragment);
		glLinkProgram(program);
		glValidateProgram(program);

		// Checks for any errors raised during the shader compilation process
		check_compile_errors(program, GL_PROGRAM);

		glDeleteShader(vertex);
		glDeleteShader(fragment);
	}

	void ShaderProgram::create_shader_program() { create_shader_program(_vShaderCode, _fShaderCode); }

	void ShaderProgram::use() const { glUseProgram(program); }

	int ShaderProgram::get_attribute_location(const std::string &name)
	{
		return glGetAttribLocation(program, name.c_str());
	}

	void ShaderProgram::set_uniform(const std::string &name, const int value) const
	{
		glUniform1i(glGetUniformLocation(program, name.c_str()), value);
	}

	void ShaderProgram::set_uniform(const std::string &name, const float value) const
	{
		glUniform1f(glGetUniformLocation(program, name.c_str()), value);
	}

	void ShaderProgram::set_uniform(const std::string &name, const glm::mat3 &trans) const
	{
		glUniformMatrix3fv(glGetUniformLocation(program, name.c_str()), 1, GL_FALSE, glm::value_ptr(trans));
	}

	void ShaderProgram::set_uniform(const std::string &name, const glm::mat4 &trans) const
	{
		glUniformMatrix4fv(glGetUniformLocation(program, name.c_str()), 1, GL_FALSE, glm::value_ptr(trans));
	}
	void ShaderProgram::set_uniform(const std::string &name, const Mat4 &trans) const
	{
		glUniformMatrix4fv(glGetUniformLocation(program, name.c_str()), 1, GL_FALSE, trans.data);
	}
} // namespace LilyPad