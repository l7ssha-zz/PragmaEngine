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
#include "AudioEngine.h"

namespace PragmaEngine {
	AudioEngine::AudioEngine() {
		musicEngine = irrklang::createIrrKlangDevice();
		soundEngine = irrklang::createIrrKlangDevice();

		if (!musicEngine || !soundEngine)
			fatalError("Could init a an Sound engine");
	}

	//Deleting Engines
	AudioEngine::~AudioEngine() {
		musicEngine->drop();
		soundEngine->drop();
	}

	void AudioEngine::playMusic(const std::string filepath, float volume)
	{
		musicEngine->setSoundVolume(volume);
		musicEngine->play2D(filepath.c_str(), true);	//play looped music ^^
	}

	void AudioEngine::playMusic(const std::string filepath, bool looped, bool startPaused, float volume)
	{
		musicEngine->setSoundVolume(volume);
		musicEngine->play2D(filepath.c_str(), looped, startPaused);	//play looped music ^^
	}

	void AudioEngine::playMusicfromplaylist(std::vector<std::string>& playlist, float volume)
	{
		musicEngine->setSoundVolume(volume);
		irrklang::ISound* snd = musicEngine->play2D(playlist[musicindex].c_str());

		if ((bool)snd->isFinished == true) {
			irrklang::ISound* snd = musicEngine->play2D(playlist[musicindex + 1].c_str());
		}
	}

	void AudioEngine::playSound(const std::string filepath, float volume)
	{
		soundEngine->setSoundVolume(volume);
		soundEngine->play2D(filepath.c_str());			//play sound(non loop)
	}

	void AudioEngine::playSound(const std::string filepath, bool looped, bool startPaused, float volume)
	{
		soundEngine->setSoundVolume(volume);
		soundEngine->play2D(filepath.c_str(), looped, startPaused);			//play sound(non loop)
	}

	void AudioEngine::pauseMusic()
	{
		musicEngine->setAllSoundsPaused(true);
	}

	void AudioEngine::resumeMusic()
	{
		musicEngine->setAllSoundsPaused(false);
	}

	void AudioEngine::stopMusic()
	{
		musicEngine->stopAllSounds();
	}
}