#include <string>
#include <map>

#include <SDL2/SDL.h>

#include "disp.h"
#include "cam.h"
#include "mesh.h"
#include "shader.h"
#include "texture.h"
#include "transform.h"
/* #include "obj.h" */

std::map<std::string, const float> size = {
	{
		"wd",
		800.0
	},
	{
		"ht",
		600.0
	}
};

int main() {
	Disp disp(size["wd"], size["ht"], "cmder");


	Cam cam(glm::vec3(0.0f, 0.0f, -5.0f), size["wd"] / size["ht"], 0.1f, 100.0f);


	Mesh mesh("jerry");
	Shader shader("basicShader");
	shader.bind();
	Texture texture("bricks");
	texture.bind();

	Transform transform;

	/* Obj jerry(mesh, shader, texture); */


	SDL_Event e;
	bool run = true;
	float counter = 0.0;

	while (run) {
		while (SDL_PollEvent(&e)) {
			bool drag;

			std::map<char, int> click = {
				{
					'x',
					0
				},
				{
					'y',
					0
				}
			};

			if (e.type == SDL_MOUSEBUTTONDOWN) {
				drag = true;

				SDL_PumpEvents();

				SDL_GetMouseState(&click['x'], &click['y']);
			}

			if (e.type == SDL_MOUSEBUTTONUP) {
				drag = false;
			}

			if (drag) {
				if (e.type == SDL_MOUSEMOTION) {
					std::map<char, int> pos = {
						{
							'x',
							0
						},
						{
							'y',
							0
						}
					};

					SDL_GetMouseState(&pos['x'], &pos['y']);

					cam.setPos({
							(click['x'] - pos['x']) / 1000.0f,
							(click['y'] - pos['y']) / 1000.0f,
							-5
							});
				}
			}

			if (e.type == SDL_MOUSEWHEEL) {
				cam.setPos({
						cam.getPos()[0],
						cam.getPos()[1],
						cam.getPos()[2] + e.wheel.y
						});
			}
		}

		disp.clear(0.0f, 0.0f, 0.0f, 1.0f);


		(*transform.getPos()).x = counter;

		shader.update(transform, cam);

		mesh.draw();

		/* jerry.draw(); */


		disp.swapBuffers();
		SDL_Delay(1);
		counter += 0.001;
	}

	return 0;
}
