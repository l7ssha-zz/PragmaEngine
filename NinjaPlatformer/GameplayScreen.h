#pragma once

#include "Box.h"
#include "Player.h"
#include <PragmaEngine/IGameScreen.h>
#include <Box2D/Box2D.h>
#include <vector>
#include <PragmaEngine/SpriteBatch.h>
#include <PragmaEngine/GLSLProgram.h>
#include <PragmaEngine/Camera2D.h>
#include <PragmaEngine/GLTexture.h>
#include <PragmaEngine/Window.h>

// Our custom gameplay screen that inherits from the IGameScreen
class GameplayScreen : public PragmaEngine::IGameScreen {
public:
    GameplayScreen(PragmaEngine::Window* window);
    ~GameplayScreen();

    virtual int getNextScreenIndex() const override;

    virtual int getPreviousScreenIndex() const override;

    virtual void build() override;

    virtual void destroy() override;

    virtual void onEntry() override;

    virtual void onExit() override;

    virtual void update() override;

    virtual void draw() override;

private:
    void checkInput();

    PragmaEngine::SpriteBatch m_spriteBatch;
    PragmaEngine::GLSLProgram m_textureProgram;
    PragmaEngine::Camera2D m_camera;
    PragmaEngine::GLTexture m_texture;
    PragmaEngine::Window* m_window;

    Player m_player;
    std::vector<Box> m_boxes;
    std::unique_ptr<b2World> m_world;
};

