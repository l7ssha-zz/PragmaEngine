#pragma once

#include <PragmaEngine/Camera2D.h>
#include <PragmaEngine/SpriteBatch.h>
#include <PragmaEngine/InputManager.h>
#include <PragmaEngine/Window.h>
#include <PragmaEngine/GLSLProgram.h>
#include <PragmaEngine/Timing.h>
#include <PragmaEngine/SpriteFont.h>
#include <PragmaEngine/pg.h>
#include <PragmaEngine/ResourceManager.h>

#include <SDL/SDL.h>
#include <random>
#include <ctime>
#include <algorithm>
#include <cmath>
#include <memory>

#include "BallController.h"
#include "BallRenderer.h"
#include "Grid.h"

// TODO:
// Visualize momentum with color
// Visualize velocity with color
// Visualize position with color

enum class GameState { RUNNING, EXIT };

const int CELL_SIZE = 12;

class MainGame {
public:
	~MainGame();
	void run();

private:
	void init();
	void initRenderers();
	void initBalls();
	void update(float deltaTime);
	void draw();
	void drawHud();
	void processInput();

	int m_screenWidth = 0;
	int m_screenHeight = 0;

	std::vector<Ball> m_balls; ///< All the balls
	std::unique_ptr<Grid> m_grid; ///< Grid for spatial partitioning for collision

	int m_currentRenderer = 0;
	std::vector<BallRenderer*> m_ballRenderers;

	BallController m_ballController; ///< Controls balls

	PragmaEngine::Window m_window; ///< The main window
	PragmaEngine::SpriteBatch m_spriteBatch; ///< Renders all the balls
	std::unique_ptr<PragmaEngine::SpriteFont> m_spriteFont; ///< For font rendering
	PragmaEngine::Camera2D m_camera; ///< Renders the scene
	PragmaEngine::InputManager m_inputManager; ///< Handles input
	PragmaEngine::GLSLProgram m_textureProgram; ///< Shader for textures]

	PragmaEngine::FpsLimiter m_fpsLimiter; ///< Limits and calculates fps
	float m_fps = 0.0f;

	GameState m_gameState = GameState::RUNNING; ///< The state of the game
};
