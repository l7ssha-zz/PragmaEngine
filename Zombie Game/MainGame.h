#pragma once

#include <PragmaEngine/Window.h>
#include <PragmaEngine/GLSLProgram.h>
#include <PragmaEngine/Camera2D.h>
#include <PragmaEngine/InputManager.h>
#include <PragmaEngine/SpriteBatch.h>
#include <PragmaEngine/pg.h>
#include <PragmaEngine/Timing.h>
#include <PragmaEngine/Errors.h>

#include <random>
#include <ctime>
#include <algorithm>
#include <SDL/SDL.h>
#include <iostream>

#include "Gun.h"
#include "Zombie.h"
#include "Player.h"
#include "Level.h"
#include "Bullet.h"

class Zombie;

enum class GameState {
    PLAY,
    EXIT
};

class MainGame
{
public:
    MainGame();
    ~MainGame();

    /// Runs the game
    void run();

private:
    /// Initializes the core systems
    void initSystems();

    /// Initializes the level and sets up everything
    void initLevel();

    /// Initializes the shaders
    void initShaders();

    /// Main game loop for the program
    void gameLoop();

    /// Updates all agents
    void updateAgents(float deltaTime);

    /// Updates all bullets
    void updateBullets(float deltaTim);

    /// Checks the victory condition
    void checkVictory();

    /// Handles input processing
    void processInput();

    /// Renders the game
    void drawGame();

    /// Member Variables
	PragmaEngine::Window _window; ///< The game window
	PragmaEngine::GLSLProgram _textureProgram; ///< The shader program
	PragmaEngine::InputManager _inputManager; ///< Handles input
	PragmaEngine::Camera2D _camera; ///< Main Camera
	PragmaEngine::SpriteBatch _agentSpriteBatch; ///< Draws all agents

    std::vector<Level*> _levels; ///< vector of all levels

    int _screenWidth, _screenHeight;
    float _fps;
    int _currentLevel;

    Player* _player;
    std::vector<Human*> _humans; ///< Vector of all humans
    std::vector<Zombie*> _zombies; ///< Vector of all zombies
    std::vector<Bullet> _bullets;

    int _numHumansKilled; ///< Humans killed by player
    int _numZombiesKilled; ///< Zombies killed by player

    GameState _gameState;
};

