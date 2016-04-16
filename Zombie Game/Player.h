#pragma once

#include <PragmaEngine/InputManager.h>
#include <PragmaEngine/Camera2D.h>

#include <SDL/SDL.h>

#include "Gun.h"
#include "Bullet.h"
#include "Human.h"

class Gun;

class Player : public Human
{
public:
    Player();
    ~Player();

    void init(float speed, glm::vec2 pos, PragmaEngine::InputManager* inputManager, PragmaEngine::Camera2D* camera, std::vector<Bullet>* bullets);

    void addGun(Gun* gun);

    void update(const std::vector<std::string>& levelData,
                std::vector<Human*>& humans,
                std::vector<Zombie*>& zombies,
                float deltaTime) override;
private:
	PragmaEngine::InputManager* _inputManager;

    std::vector<Gun*> _guns;
    int _currentGunIndex;

	PragmaEngine::Camera2D* _camera;
    std::vector<Bullet>* _bullets;

};

