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

		int musicindex = 0;

		void playMusic(const std::string filepath, float volume);
		void playMusic(const std::string filepath, bool looped, bool startPaused, float volume);

		void playMusicfromplaylist(std::vector<std::string>& playlist, float volume);

		void playSound(const std::string filepath, float volume);
		void playSound(const std::string filepath, bool looped, bool startPaused, float volume);

		void pauseMusic();
		void resumeMusic();
		void stopMusic();
	private:
		irrklang::ISoundEngine* musicEngine;
		irrklang::ISoundEngine* soundEngine;
	};
}