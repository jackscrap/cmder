#pragma once

#include <string>
#include <GL/glew.h>
#include "transform.h"

class Shader {
	private:
		static const unsigned int NUM_SHADERS = 2,
								 							NUM_UNIFORMS = 3;

		/* Shader(const Shader& shader) { */
		/* } */

		std::string loadShader(const std::string& fileName);
		void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
		GLuint createShader(const std::string& text, unsigned int type);

		GLuint m_program;
		GLuint m_shaders[NUM_SHADERS];
		GLuint m_uniforms[NUM_UNIFORMS];

	public:
		Shader(const std::string& fName);

		void bind();
		void update(const Transform& transform, const Cam& cam);

		virtual ~Shader();
};
