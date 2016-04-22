#pragma once

#include <glm\glm.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <random>
#include <ctime>
#include <algorithm>
#include <SDL/SDL.h>
#include <iostream>

#include <PragmaEngine/Window.h>
#include <PragmaEngine/GLSLProgram.h>
#include <PragmaEngine/Camera2D.h>
#include <PragmaEngine/InputManager.h>
#include <PragmaEngine/SpriteBatch.h>
#include <PragmaEngine/SpriteFont.h>
#include <PragmaEngine\ParticleBatch2D.h>
#include <PragmaEngine\ParticleEngine2D.h>
#include <PragmaEngine\ResourceManager.h>
#include <PragmaEngine/pg.h>
#include <PragmaEngine/Timing.h>
#include <PragmaEngine/Errors.h>
#include <PragmaEngine\AudioEngine.h>

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

	/// Draws the HUD
	void drawHud();

	/// Adds blood to the particle engine
	void addBlood(const glm::vec2& position, int numParticles);

	PragmaEngine::ParticleEngine2D m_particleEngine;
	PragmaEngine::ParticleBatch2D* m_bloodParticleBatch;

	/// Member Variables
	PragmaEngine::Window m_window; ///< The game window

	PragmaEngine::GLSLProgram m_textureProgram; ///< The shader program

	PragmaEngine::InputManager m_inputManager; ///< Handles input

	PragmaEngine::Camera2D m_camera; ///< Main Camera
	PragmaEngine::Camera2D m_hudCamera; ///< Hud Camera

	PragmaEngine::SpriteBatch m_agentSpriteBatch; ///< Draws all agents
	PragmaEngine::SpriteBatch m_hudSpriteBatch;

	std::vector<Level*> m_levels; ///< vector of all levels

	int m_screenWidth = 1024;
	int m_screenHeight = 768;

	float m_fps;

	int m_currentLevel;

	Player* m_player;
	std::vector<Human*> m_humans; ///< Vector of all humans
	std::vector<Zombie*> m_zombies; ///< Vector of all zombies
	std::vector<Bullet> m_bullets;

	int m_numHumansKilled; ///< Humans killed by player
	int m_numZombiesKilled; ///< Zombies killed by player

	PragmaEngine::SpriteFont* m_spriteFont;

	PragmaEngine::AudioEngine m_audioengine;

	GameState m_gameState;
};
