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
#include "IMainGame.h"
#include "Timing.h"

#include "ScreenList.h"
#include "IGameScreen.h"

namespace PragmaEngine {

    IMainGame::IMainGame() {
        m_screenList = std::make_unique<ScreenList>(this);
    }

    IMainGame::~IMainGame() {
        // Empty
    }

    void IMainGame::run() {

        if (!init()) return;

        FpsLimiter limiter;
        limiter.setMaxFPS(60.0f);

        // Game loop
        m_isRunning = true;
        while (m_isRunning) {
            limiter.begin();

            // Call the custom update and draw method
            inputManager.update();
            update();
            draw();

            m_fps = limiter.end();
            m_window.swapBuffer();
        }

    }

    void IMainGame::exitGame() {
        m_currentScreen->onExit();
        if (m_screenList) {
            m_screenList->destroy();
            m_screenList.reset();
        }
        m_isRunning = false;
    }

    void IMainGame::onSDLEvent(SDL_Event& evnt) {
        switch (evnt.type) {
            case SDL_QUIT:
                exitGame();
                break;
            case SDL_MOUSEMOTION:
                inputManager.setMouseCoords((float)evnt.motion.x, (float)evnt.motion.y);
                break;
            case SDL_KEYDOWN:
                inputManager.pressKey(evnt.key.keysym.sym);
                break;
            case SDL_KEYUP:
                inputManager.releaseKey(evnt.key.keysym.sym);
                break;
            case SDL_MOUSEBUTTONDOWN:
                inputManager.pressKey(evnt.button.button);
                break;
            case SDL_MOUSEBUTTONUP:
                inputManager.releaseKey(evnt.button.button);
                break;
        }
    }

    bool IMainGame::init() {
		PragmaEngine::init();

        SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

        if (!initSystems()) return false;

        onInit();
        addScreens();

        m_currentScreen = m_screenList->getCurrent();
        m_currentScreen->onEntry();
        m_currentScreen->setRunning();

        return true;
    }

    bool IMainGame::initSystems() {
        m_window.create("Default", 1024, 768, 0);
        return true;
    }


    void IMainGame::update() {
        if (m_currentScreen) {
            switch (m_currentScreen->getState()) {
                case ScreenState::RUNNING:
                    m_currentScreen->update();
                    break;
                case ScreenState::CHANGE_NEXT:
                    m_currentScreen->onExit();
                    m_currentScreen = m_screenList->moveNext();
                    if (m_currentScreen) {
                        m_currentScreen->setRunning();
                        m_currentScreen->onEntry();
                    }
                    break;
                case ScreenState::CHANGE_PREVIOUS:
                    m_currentScreen->onExit();
                    m_currentScreen = m_screenList->movePrevious();
                    if (m_currentScreen) {
                        m_currentScreen->setRunning();
                        m_currentScreen->onEntry();
                    }
                    break;
                case ScreenState::EXIT_APPLICATION:
                    exitGame();
                    break;
                default:
                    break;
            }
        } else {
            exitGame();
        }
    }

    void IMainGame::draw() {
        glViewport(0, 0, m_window.getScreenWidth(), m_window.getScreenHeight());
        if (m_currentScreen && m_currentScreen->getState() == ScreenState::RUNNING) {
            m_currentScreen->draw();
        }
    }
}