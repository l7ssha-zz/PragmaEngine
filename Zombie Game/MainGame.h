#pragma once

#include <PragmaEngine/Window.h>
#include <PragmaEngine/GLSLProgram.h>
#include <PragmaEngine/Camera2D.h>
#include <PragmaEngine/InputManager.h>
#include <PragmaEngine/SpriteBatch.h>
#include <PragmaEngine/SpriteFont.h>
#include <PragmaEngine/AudioEngine.h>
#include <PragmaEngine/ParticleEngine2D.h>
#include <PragmaEngine/ParticleBatch2D.h>

#include "Player.h"
#include "Level.h"
#include "Bullet.h"
#include "Grid.h"

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

	/// Checks the victory condition
	void checkVictory();

	/// Handles input processing
	void processInput();

	/// Renders the game
	void drawGame();

	/// Draws the HUD
	void drawHud();

	/// Member Variables
	PragmaEngine::Window m_window; ///< The game window

	PragmaEngine::GLSLProgram m_textureProgram; ///< The shader program

	PragmaEngine::InputManager m_inputManager; ///< Handles input

	PragmaEngine::Camera2D m_camera; ///< Main Camera
	PragmaEngine::Camera2D m_hudCamera; ///< Hud Camera

	PragmaEngine::SpriteBatch m_agentSpriteBatch; ///< Draws all agents
	PragmaEngine::SpriteBatch m_hudSpriteBatch;

	PragmaEngine::ParticleEngine2D m_particleEngine;
	PragmaEngine::ParticleBatch2D* m_bloodParticleBatch;

	std::vector<Level*> m_levels; ///< vector of all levels

	int m_screenWidth = 1024;
	int m_screenHeight = 768;

	float m_fps;

	int m_currentLevel;

	Player* m_player;
	Grid m_grid;

	int m_numHumansKilled; ///< Humans killed by player
	int m_numZombiesKilled; ///< Zombies killed by player

	PragmaEngine::SpriteFont* m_spriteFont;

	PragmaEngine::AudioEngine m_audioEngine;

	int m_totalZombies = 0;
	int m_totalHumans = 0;

	GameState m_gameState;

	std::vector<std::string> _playlist = { "Sound/shots/cg1.wav", "Sound/shots/pistol.wav", "Sound/shots/rifle.wav", "Sound/shots/shotgun.wav" };

};
