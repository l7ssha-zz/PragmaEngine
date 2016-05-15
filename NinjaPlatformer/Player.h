#pragma once

#include "Capsule.h"
#include <PragmaEngine/InputManager.h>
#include <PragmaEngine/SpriteBatch.h>
#include <PragmaEngine/TileSheet.h>

enum class PlayerMoveState {STANDING, RUNNING, PUNCHING, IN_AIR };

class Player {
public:
    void init(b2World* world,
              const glm::vec2& position,
              const glm::vec2& drawDims,
              glm::vec2& collisionDims,
              PragmaEngine::ColorRGBA8 color);

    void draw(PragmaEngine::SpriteBatch& spriteBatch);
    void drawDebug(PragmaEngine::DebugRenderer& debugRenderer);

    void update(PragmaEngine::InputManager& inputManager);

    const Capsule& getCapsule() const { return m_capsule; }

    glm::vec2 getPosition() const {
        glm::vec2 rv;
        rv.x = m_capsule.getBody()->GetPosition().x;
        rv.y = m_capsule.getBody()->GetPosition().y;
        return rv;
    }

private:
    glm::vec2 m_drawDims;
    PragmaEngine::ColorRGBA8 m_color;
    PragmaEngine::TileSheet m_texture;
    Capsule m_capsule;
    PlayerMoveState m_moveState = PlayerMoveState::STANDING;
    float m_animTime = 0.0f;
    int m_direction = 1; // 1 or -1
    bool m_onGround = false;
    bool m_isPunching = false;
};

