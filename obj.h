#pragma once

#include <string>

#include "mesh.h"
#include "shader.h"
#include "texture.h"
#include "cam.h"
#include "transform.h"

class Obj {
	public:
		Mesh m_mesh;
		Shader m_shader;
		Texture m_texture;
		Cam m_cam;
		Transform m_transform;

		Obj(Mesh mesh, Shader shader, Texture texture, Cam cam, Transform transform);

		void draw();

		~Obj();
};
