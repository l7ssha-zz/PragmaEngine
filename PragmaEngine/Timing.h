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

namespace PragmaEngine {
	///Calculates FPS and also limits FPS
	class FpsLimiter {
	public:
		FpsLimiter();

		// Initializes the FPS limiter. For now, this is
		// analogous to setMaxFPS
		void init(float maxFPS);

		// Sets the desired max FPS
		void setMaxFPS(float maxFPS);

		void begin();

		// end() will return the current FPS as a float
		float end();
	private:
		// Calculates the current FPS
		void calculateFPS();

		// Variables
		float _fps;
		float _maxFPS;
		float _frameTime;
		unsigned int _startTicks;
	};
}