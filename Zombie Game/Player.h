#pragma once

#include "Human.h"
#include <PragmaEngine/InputManager.h>
#include <PragmaEngine/Camera2D.h>
#include "Bullet.h"

class Gun;

class Player : public Human
{
public:
	Player();
	~Player();

	void init(float speed, glm::vec2 pos, PragmaEngine::InputManager* inputManager, PragmaEngine::Camera2D* camera, Grid* grid);

	void addGun(Gun* gun);

	void update(const std::vector<std::string>& levelData,
		float deltaTime) override;
private:
	PragmaEngine::InputManager* _inputManager;

	std::vector<Gun*> _guns;
	int _currentGunIndex;

	PragmaEngine::Camera2D* _camera;
};
