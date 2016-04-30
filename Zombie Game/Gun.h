#pragma once
#include <string>
#include <vector>
#include <glm/glm.hpp>
#include <PragmaEngine/AudioEngine.h>

#include "Bullet.h"

class Grid;

class Gun
{
public:
	Gun(std::string name, int fireRate, int bulletsPerShot,
		float spread, float bulletDamage, float bulletSpeed, std::string audiopath);
	~Gun();

	void update(bool isMouseDown, const glm::vec2& position, const glm::vec2& direction, Grid* grid, float deltaTime);

private:

	PragmaEngine::AudioEngine m_audio;

	void fire(const glm::vec2& direction, const glm::vec2& position, Grid* grid);

	std::string _name;
	std::string _audiopath;

	int _fireRate; ///< Fire rate in terms of frames

	int _bulletsPerShot; ///< How many bullets are fired at at time

	float _spread; ///< Accuracy

	float _bulletSpeed;

	int _bulletDamage;

	float _frameCounter; ///< Counts frames so we know when to shoot bullets
};
