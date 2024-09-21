#include "shader_program.hpp"

#include <GL/glew.h>
#include <fstream>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <sstream>
#include "Lys/core/math/generic.hpp"
#include "Lys/debug/logging.hpp"

namespace Lys
{
	Shader::Shader(const std::string &path, unsigned int type) : File(path)
	{
		_shaderCode = read_file();
	}

	void Shader::update()
	{
		if (is_updated())
		{
			_lastTime = std::filesystem::last_write_time(_path);
			_shaderCode = read_file(_path);
		}
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

	ShaderProgram::ShaderProgram(const std::string &path, const std::string &vertex,
								 const std::string &fragment) :
		_path(path), _vShader(path + vertex, GL_VERTEX_SHADER),
		_fShader(path + fragment, GL_FRAGMENT_SHADER)
	{
	}

	ShaderProgram::~ShaderProgram() { glDeleteProgram(id); }

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
				LYS_ERROR("ERROR::SHADER_COMPILATION_ERROR of type: ", type, "\n", infoLog,
						  "-- --------------------------------------------------- --");
			}
		}
		else
		{
			glGetProgramiv(shader, GL_LINK_STATUS, &success);
			if (!success)
			{
				glGetProgramInfoLog(shader, 1024, nullptr, infoLog);
				LYS_ERROR("ERROR::PROGRAM_LINKING_ERROR of type: ", type, "\n", infoLog,
						  "-- --------------------------------------------------- --");
			}
		}

		return success;
	}

	void ShaderProgram::create_shader_program()
	{
		if (id)
		{
			glDeleteProgram(id);
		}
		id = glCreateProgram();
		const unsigned int vertex = compile_shader(_vShader.read_file(), GL_VERTEX_SHADER);
		LYS_DEBUG("Finished compiling vertex shader.");
		const unsigned int fragment = compile_shader(_fShader.read_file(), GL_FRAGMENT_SHADER);
		LYS_DEBUG("Finished compiling fragment shader.");

		// Loads the shaders to the program
		glAttachShader(id, vertex);
		glAttachShader(id, fragment);
		glLinkProgram(id);
		glValidateProgram(id);

		// Checks for any errors raised during the shader compilation process
		check_compile_errors(id, GL_PROGRAM);

		glDeleteShader(vertex);
		glDeleteShader(fragment);
	}

	void ShaderProgram::use() const { glUseProgram(id); }

	int ShaderProgram::get_attribute_location(const std::string &name) const
	{
		return glGetAttribLocation(id, name.c_str());
	}

	void ShaderProgram::set_uniform(const std::string &name, const int value) const
	{
		glUniform1i(glGetUniformLocation(id, name.c_str()), value);
	}

	void ShaderProgram::set_uniform(const std::string &name, const unsigned int value) const
	{
		glUniform1ui(glGetUniformLocation(id, name.c_str()), value);
	}

	void ShaderProgram::set_uniform(const std::string &name, const float value) const
	{
		glUniform1f(glGetUniformLocation(id, name.c_str()), value);
	}

	void ShaderProgram::set_uniform(const std::string &name, const glm::mat3 &trans) const
	{
		glUniformMatrix3fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE,
						   glm::value_ptr(trans));
	}

	void ShaderProgram::set_uniform(const std::string &name, const glm::mat4 &trans) const
	{
		glUniformMatrix4fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE,
						   glm::value_ptr(trans));
	}

	void ShaderProgram::set_uniform(const std::string &name, const Matrix4 &trans) const
	{
		glUniformMatrix4fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE,
						   LysMath::value_ptr(trans));
	}

	void ShaderProgram::reload()
	{
		_vShader.update();
		_fShader.update();
		create_shader_program();
	}
} // namespace Lys
