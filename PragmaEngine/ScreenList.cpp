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
#include "ScreenList.h"

#include "IGameScreen.h"

namespace PragmaEngine {

    ScreenList::ScreenList(IMainGame* game) :
        m_game(game) {
        // Empty
    }

    ScreenList::~ScreenList() {
        destroy();
    }

    IGameScreen* PragmaEngine::ScreenList::moveNext() {
        IGameScreen* currentScreen = getCurrent();
        if (currentScreen->getNextScreenIndex() != SCREEN_INDEX_NO_SCREEN) {
            m_currentScreenIndex = currentScreen->getNextScreenIndex();
        }
        return getCurrent();
    }

    IGameScreen* PragmaEngine::ScreenList::movePrevious() {
        IGameScreen* currentScreen = getCurrent();
        if (currentScreen->getPreviousScreenIndex() != SCREEN_INDEX_NO_SCREEN) {
            m_currentScreenIndex = currentScreen->getPreviousScreenIndex();
        }
        return getCurrent();
    }

    void PragmaEngine::ScreenList::setScreen(int nextScreen) {
        m_currentScreenIndex = nextScreen;
    }

    void PragmaEngine::ScreenList::addScreen(IGameScreen* newScreen) {
        newScreen->m_screenIndex = m_screens.size();
        m_screens.push_back(newScreen);
        newScreen->build();
        newScreen->setParentGame(m_game);
    }

    void PragmaEngine::ScreenList::destroy() {
        for (size_t i = 0; i < m_screens.size(); i++) {
            m_screens[i]->destroy();
        }
        m_screens.resize(0);
        m_currentScreenIndex = SCREEN_INDEX_NO_SCREEN;
    }

    IGameScreen* ScreenList::getCurrent() {
        if (m_currentScreenIndex == SCREEN_INDEX_NO_SCREEN) return nullptr;
        return m_screens[m_currentScreenIndex];
    }

}