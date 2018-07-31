#pragma once

#include <glm/glm.hpp>

#include <string>

#include "mesh.h"
#include "shader.h"
#include "texture.h"
#include "transform.h"
#include "cam.h"

class Obj {
	public:
		Mesh m_mesh;
		Shader m_shader;
		Texture m_texture;
		Transform m_transform;
		Cam m_cam;

		glm::vec3 m_pos;

		Obj(Mesh& mesh, Shader& shader, Texture& texture, Transform& transform, Cam& cam);

		void draw();

		~Obj();
};
