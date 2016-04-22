#pragma once

#include <glm/glm.hpp>
#include <PragmaEngine/Vertex.h>

// POD
struct Ball {
	Ball(float radius, float mass, const glm::vec2& pos,
		const glm::vec2& vel, unsigned int textureId,
		const PragmaEngine::ColorRGBA8& color);

	float radius;
	float mass;
	glm::vec2 velocity;
	glm::vec2 position;
	unsigned int textureId = 0;
	PragmaEngine::ColorRGBA8 color;
};
