/*
------------------------- PragmaEngine BY L7SSHA | ALL RIGTS RESERVED -------------------------
PragamEngine version 3.0
Copyright (c) 2016 Szymon "l7ssha" Uglis

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.
Permission is granted to no one to use this software for any purpose,
including commercial application

------------------------- PragmaEngine BY L7SSHA | ALL RIGTS RESERVED -------------------------
*/
#pragma once

#include <string>
#include <vector>

#include <irrklang\irrKlang.h>

#include "Errors.h"

namespace PragmaEngine {
	class AudioEngine {
	public:
		AudioEngine();
		~AudioEngine();

		void playMusic(const std::string filepath, float volume);
		void playMusic(const std::string filepath, bool looped, bool startPaused, float volume);
		//void playMusicfromplaylist(std::vector<std::string>& playlist, float volume);

		void playSound(const std::string filepath, float volume);
		void playSound(const std::string filepath, bool looped, bool startPaused, float volume);

		void pauseMusic();
		void resumeMusic();
		void stopMusic();
	private:
		int musicindex = 0;

		irrklang::ISoundEngine* musicEngine;
		irrklang::ISoundEngine* soundEngine;
	};
}