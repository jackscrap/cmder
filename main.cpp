#include <string>
#include <map>
#include <iostream>

#include <SDL2/SDL.h>

#include "disp.h"
#include "cam.h"
#include "mesh.h"
#include "shader.h"
#include "texture.h"
#include "transform.h"
#include "obj.h"

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


	Cam cam(glm::vec3(0.0f, 5.0f, -25.0f), size["wd"] / size["ht"], 0.1f, 100.0f);


	/* Mesh mesh("monkey3"); */
	/* Shader shader("basicShader"); */
	/* Texture texture("bricks"); */

	/* shader.bind(); */
	/* texture.bind(); */

	/* Transform transform; */


	Mesh mesh2("monkey3");
	Shader shader2("basicShader");
	Texture texture2("bricks");

	shader2.bind();
	texture2.bind();

	Transform transform2;

	Obj obj(mesh2, shader2, texture2, cam, transform2);


	/* Mesh terrain("terrain"); */
	/* Shader shader3("grass"); */
	/* shader3.bind(); */
	/* Texture texture3("bricks"); */
	/* texture3.bind(); */

	/* Transform transform3; */


	SDL_Event e;
	bool run = true;
	float counter = 0.0;

	while (run) {
		while (SDL_PollEvent(&e)) {
			bool drag;

			std::map<char, int> click;

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
					std::map<char, int> pos;

					SDL_GetMouseState(&pos['x'], &pos['y']);

					cam.setPos({
							(click['x'] - pos['x']) / 1000.0f,
							(click['y'] - pos['y']) / 1000.0f,
							cam.getPos()[2]
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
		/* disp.clear(0.53, 0.59, 0.43, 1); */


		/* terrain.draw(); */

		/* (*transform.getPos()).x = counter; */
		/* shader.update(transform, cam); */
		/* mesh.draw(); */

		std::cout << (*obj.m_transform.getPos()).x << std::endl;
		obj.m_shader.update(obj.m_transform, cam);
		obj.m_mesh.draw();


		disp.swapBuffers();
		SDL_Delay(1);
		counter += 0.001;
	}

	return 0;
}
