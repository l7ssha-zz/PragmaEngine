#pragma once

#include <glm/glm.hpp>
#include <PragmaEngine/SpriteBatch.h>

const float AGENT_WIDTH = 60.0f;
const float AGENT_RADIUS = AGENT_WIDTH / 2.0f;

class Zombie;
class Human;
class Grid;
class Cell;

class Agent
{
public:
	Agent();
	virtual ~Agent();

	virtual void update(const std::vector<std::string>& levelData,
		float deltaTime) = 0;

	bool collideWithLevel(const std::vector<std::string>& levelData);

	bool collideWithAgent(Agent* agent);

	void draw(PragmaEngine::SpriteBatch& _spriteBatch);

	// Return true if we died
	bool applyDamage(float damage);

	glm::vec2 getPosition() const { return _position; }

protected:

	void checkTilePosition(const std::vector<std::string>& levelData,
		std::vector<glm::vec2>& collideTilePositions,
		float x,
		float y);

	void collideWithTile(glm::vec2 tilePos);

	glm::vec2 _position;
	glm::vec2 m_direction = glm::vec2(1.0f, 0.0f);
	PragmaEngine::ColorRGBA8 _color;
	float _speed;
	float _health;
	GLuint m_textureID;
	Grid* m_grid = nullptr;
};
