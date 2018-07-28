#include <string>
#include <iostream>

#include "obj.h"

Obj::Obj(Mesh mesh, Shader shader, Texture texture, Cam cam, Transform transform) : m_mesh(mesh), m_shader(shader), m_texture(texture), m_cam(cam), m_transform(transform) {
	(*this).m_mesh = mesh;
	(*this).m_shader = shader;
	(*this).m_texture = texture;
	(*this).m_cam = cam;
	(*this).m_transform = transform;

	(*this).m_shader.bind();
	(*this).m_texture.bind();
}

void Obj::draw() {
	/* (*m_transform.getPos()).x += 0.001; */
	/* (*this).m_shader.update(m_transform, m_cam); */
	/* (*this).m_mesh.draw(); */
}

Obj::~Obj() {
}
