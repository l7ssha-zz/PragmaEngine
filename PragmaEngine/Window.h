/*
------------------------- PragmaEngine BY L7SSHA | ALL RIGTS RESERVED -------------------------
PragamEngine version 2.0
Copyright (c) 2016 Szymon "l7ssha" Uglis

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to no one to use this software for any purpose,
including commercial application

------------------------- PragmaEngine BY L7SSHA | ALL RIGTS RESERVED -------------------------
*/

#pragma once

#include <SDL/SDL.h>
#include <GL/glew.h>
#include <string>

#include "Errors.h"

namespace PragmaEngine {
	enum WindowFlags { INVISIBLE = 0x1, FULLSCREEN = 0x2, BORDERLESS = 0x4 };

	class Window
	{
	public:
		Window();
		~Window();

		int create(std::string windowName, int screenWidth, int screenHeight, unsigned int currentFlags);

		void swapBuffer();

		int getScreenWidth() { return _screenWidth; }
		int getScreenHeight() { return _screenHeight; }
	private:
		SDL_Window* _sdlWindow;
		int _screenWidth, _screenHeight;
	};
}