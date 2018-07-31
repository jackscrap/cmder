#include <string>
#include <map>
#include <vector>
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


	Cam cam(glm::vec3(0.0f, 25, -40), size["wd"] / size["ht"], 0.1f, 100.0f);


	Mesh terrain("terrain");
	Shader shader3("grass");
	shader3.bind();
	Texture texture3("bricks");
	texture3.bind();


	std::vector<Obj> forest;

	/* for (int i = 0; i < 10; i++) { */
	/* 	Mesh tree("tree"); */
	/* 	Shader shader4("grass"); */
	/* 	shader4.bind(); */
	/* 	Texture texture4("bricks"); */
	/* 	texture4.bind(); */

	/* 	forest.push_back(tree); */
	/* } */

	Mesh tree6("tree");

	Shader shader6("grass");
	Texture texture6("bricks");

	shader6.bind();
	texture6.bind();

	Transform transform6;

	Obj tree(tree6, shader6, texture6, transform6, cam);
	forest.push_back(tree);


	Mesh tree7("tree");

	Shader shader7("grass");
	Texture texture7("bricks");

	shader7.bind();
	texture7.bind();

	Transform transform7;

	Obj tree2(tree7, shader7, texture7, transform7, cam);
	forest.push_back(tree2);


	Mesh turret("turret");
	Shader shader5("grass");
	shader5.bind();
	Texture texture5("bricks");
	texture5.bind();

	Transform transform5;


	float deg = glm::radians(90.0f);

	SDL_Event e;
	bool run = true;
	float counter = 0.0;

	std::map<char, int> click,
		current;
	while (run) {
		while (SDL_PollEvent(&e)) {
			bool drag;

			if (e.type == SDL_MOUSEBUTTONDOWN) {
				drag = true;

				SDL_PumpEvents();
				SDL_GetMouseState(&click['x'], &click['y']);
			}

			if (drag) {
				if (e.type == SDL_MOUSEMOTION) {
					SDL_PumpEvents();
					SDL_GetMouseState(&current['x'], &current['y']);

					if (click['x'] - click['y'] > 0) {
						if (cam.getPos().x < 10) {
							cam.pan((click['x'] - current['x']) / 3000.0f);
						}
					}

					if (click['x'] - click['y'] < 0) {
						if (cam.getPos().x > -10) {
							cam.pan((click['x'] - current['x']) / 3000.0f);
						}
					}
				}
			}

			if (e.type == SDL_MOUSEBUTTONUP) {
				drag = false;
			}

			if (e.type == SDL_MOUSEWHEEL) {
				if (e.wheel.y == -1) {
					if (cam.getPos().z > -30) {
						cam.zoom(e.wheel.y * 3);
					}
				}

				if (e.wheel.y == 1) {
					if (cam.getPos().z < -18) {
						cam.zoom(e.wheel.y * 3);
					}
				}
			}
		}

		disp.clear(0.53, 0.59, 0.43, 0.6);


		terrain.draw();
		forest[1].draw();


		/* glm::vec3 rot = glm::vec3(0, counter, 0); */

		/* if (counter < deg) { */
		/* 	counter += 0.01; */
		/* } */

		/* transform5.setScale(glm::vec3(0.1f, 0.1f, 0.1f)); */
		/* shader5.update(transform5, cam); */
		/* turret.draw(); */


		disp.swapBuffers();
		SDL_Delay(1);
	}

	return 0;
}
