#pragma once

#include <string>
#include <vector>
#include <map>

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "obj_loader.h"

struct Vertex {
	private:
		glm::vec3 pos;
		glm::vec2 texCoord;
		glm::vec3 normal;

	public:
		Vertex(const glm::vec3& pos, const glm::vec2& texCoord, const glm::vec3& normal) {
			(*this).pos = pos;
			(*this).texCoord = texCoord;
			(*this).normal = normal;
		}

		glm::vec3* getPos() {
			return &pos;
		}

		glm::vec2* getTexCoord() {
			return &texCoord;
		}

		glm::vec3* getNormal() {
			return &normal;
		}
};

enum MeshBufferPositions {
	POSITION_VB,
	TEXCOORD_VB,
	NORMAL_VB,
	INDEX_VB
};

class Mesh {
	private:
		static const unsigned int NUM_BUFFERS = 4;

		Mesh(const Mesh& mesh) {
		}

		void initMesh(const IndexedModel& model);

		GLuint m_vertexArrayObject;
		GLuint m_vertexArrayBuffers[NUM_BUFFERS];
		unsigned int m_numIndices;

	public:
		Mesh(const std::string& fName);
		Mesh(Vertex* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices);

		std::map<char, float> pos = {
			{
				'x',
				0
			},
			{
				'y',
				0
			},
			{
				'z',
				0
			}
		};

		void move(char axis);
		void draw();

		~Mesh();
};
