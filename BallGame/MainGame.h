#pragma once

#include <PragmaEngine/Camera2D.h>
#include <PragmaEngine/SpriteBatch.h>
#include <PragmaEngine/InputManager.h>
#include <PragmaEngine/Window.h>
#include <PragmaEngine/GLSLProgram.h>
#include <PragmaEngine/Timing.h>
#include <PragmaEngine/SpriteFont.h>

#include <memory>

#include "BallController.h"
#include "BallRenderer.h"

enum class GameState { RUNNING, EXIT };

class MainGame {
public:
	void run();

private:
	void init();
	void initBalls();
	void update(float deltaTime);
	void draw();
	void drawHud();
	void processInput();

	int m_screenWidth = 0;
	int m_screenHeight = 0;

	std::vector<Ball> m_balls; ///< All the balls

	BallController m_ballController; ///< Controls balls
	BallRenderer m_ballRenderer; ///< Renders balls

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
