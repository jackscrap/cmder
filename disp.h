#pragma once

#include <string>
#include <SDL2/SDL.h>

class Disp {
	private:
		void operator = (const Disp& display) {}
		Disp(const Disp& display) {}

		SDL_Window* m_window;
		SDL_GLContext m_glContext;

	public:
		Disp(int width, int height, const std::string& title);

		void Clear(float r, float g, float b, float a);
		void SwapBuffers();

		virtual ~Disp();
};
