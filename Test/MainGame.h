#pragma once

#include <SDL/SDL.h>
#include <GL/glew.h>
#include <iostream>
#include <string>
#include <vector>

#include <PragmaEngine/pg.h>
#include <PragmaEngine/GLSLProgram.h>
#include <PragmaEngine/GLTexture.h>
#include <PragmaEngine/Sprite.h>
#include <PragmaEngine/Window.h>
#include <PragmaEngine/InputManager.h>
#include <PragmaEngine/Timing.h>
#include <PragmaEngine\Errors.h>
#include <PragmaEngine/ResourceManager.h>
#include <PragmaEngine/SpriteBatch.h>
#include <PragmaEngine/Camera2D.h>

#include "Bullet.h"

enum class GameState { PLAY, EXIT };

//Our example game class, just for testing purposes right now
class MainGame
{
public:
	MainGame();
	~MainGame();

	void run();

private:
	void initSystems();
	void initShaders();
	void gameLoop();
	void processInput();
	void drawGame();

	PragmaEngine::Window _window;
	int _screenWidth;
	int _screenHeight;
	GameState _gameState;

	PragmaEngine::GLSLProgram _colorProgram;
	PragmaEngine::Camera2D _camera;

	PragmaEngine::SpriteBatch _spriteBatch;

	PragmaEngine::InputManager _inputManager;
	PragmaEngine::FpsLimiter _fpsLimiter;

	std::vector<Bullet> _bullets;

	float _maxFPS;
	float _fps;
	float _time;
};
