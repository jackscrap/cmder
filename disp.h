#pragma once

#include <string>
#include <SDL2/SDL.h>

class Disp {
	private:
		Disp(const Disp& display) {}

		SDL_Window* m_window;
		SDL_GLContext m_glContext;

	public:
		Disp(int width, int height, const std::string& title);

		void clear(float r, float g, float b, float a);
		void swapBuffers();

		virtual ~Disp();
};
