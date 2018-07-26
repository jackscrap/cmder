#pragma once

#include <string>

#include "mesh.h"
#include "shader.h"
#include "texture.h"
#include "classTest.h"

class Obj {
	public:
		Obj(std::string fName);

		classTest test;

		void draw();

		~Obj();
};
