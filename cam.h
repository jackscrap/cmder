#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

struct Cam {
	private:
		glm::mat4 projection;
		glm::vec3 pos,
							forward,
							up;

	public:
		Cam(const glm::vec3& pos, float aspect, float zNear, float zFar) {
			this->pos = pos;

			this->forward = glm::vec3(0.0f, 0.0f, 1.0f);
			this->up = glm::vec3(0.0f, 1.0f, 0.0f);

			this->projection = glm::perspective(70.0f, aspect, zNear, zFar);
		}

		glm::mat4 getViewProjection() const {
			return projection * glm::lookAt(pos, glm::vec3(0, 0, 0) + forward, up);
		}

		glm::vec3 getPos() {
			return pos;
		}

		void setPos(glm::vec3 pos) {
			this->pos = pos;
		}

		void pan(float inc) {
			this->setPos({
					this->pos.x + inc,
					this->pos.y,
					this->pos.z
					});
		}

		void zoom(float inc) {
			this->setPos({
					this->pos.x,
					this->pos.y - (inc * 0.6),
					this->pos.z + inc
					});
		}

		//void Pitch(float angle) {
		//	glm::vec3 right = glm::normalize(glm::cross(up, forward));

		//	forward = glm::vec3(glm::normalize(glm::rotate(angle, right) * glm::vec4(forward, 0.0)));
		//	up = glm::normalize(glm::cross(forward, right));
		//}

		//void RotateY(float angle) {
		//	static const glm::vec3 UP(0.0f, 1.0f, 0.0f);

		//	glm::mat4 rotation = glm::rotate(angle, UP);

		//	forward = glm::vec3(glm::normalize(rotation * glm::vec4(forward, 0.0)));
		//	up = glm::vec3(glm::normalize(rotation * glm::vec4(up, 0.0)));
		//}
};
