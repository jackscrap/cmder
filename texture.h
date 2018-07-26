#pragma once

#include <string>

#include <GL/glew.h>

class Texture {
	private:
		Texture(const Texture& texture) {
		}

		GLuint m_texture;

	public:
		Texture(const std::string& fName);

		void bind();

		~Texture();
};
