#include <string>
#include <iostream>

#include <glm/glm.hpp>

#include "obj.h"

Obj::Obj(Mesh& mesh, Shader& shader, Texture& texture, Transform& transform, Cam& cam)
	: m_mesh(mesh), m_shader(shader), m_texture(texture), m_transform(transform), m_cam(cam) {
		this->m_mesh = mesh;
		this->m_shader = shader;
		this->m_texture = texture;
		this->m_transform = transform;
		this->m_cam = cam;

		this->m_shader.bind();
		this->m_texture.bind();

		float x = -10,
					z = -10;
		this->m_pos = glm::vec3(x, 10, z);
	}

void Obj::draw() {
	this->m_transform.setPos(m_pos);
	/* float inc = 0.01f; */

	/* m_transform.getPos().x += 0.01; */
	this->m_shader.update(m_transform, m_cam);
	this->m_mesh.draw();
}

Obj::~Obj() {
}
