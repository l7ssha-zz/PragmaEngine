#pragma once

#include "Box.h"
#include <PragmaEngine/InputManager.h>
#include <PragmaEngine/SpriteBatch.h>
#include <PragmaEngine/GLTexture.h>

class Player {
public:
    Player();
    ~Player();

    void init(b2World* world, const glm::vec2& position, const glm::vec2& dimensions, PragmaEngine::ColorRGBA8 color);

    void draw(PragmaEngine::SpriteBatch& spriteBatch);

    void update(PragmaEngine::InputManager& inputManager);

    const Box& getBox() const { return m_collisionBox; }

private:
    Box m_collisionBox;
};

