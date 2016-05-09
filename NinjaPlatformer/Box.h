#pragma once

#include <Box2D/Box2D.h>
#include <glm/glm.hpp>
#include <PragmaEngine/Vertex.h>
#include <PragmaEngine/SpriteBatch.h>
#include <PragmaEngine/GLTexture.h>

class Box {
public:
    Box();
    ~Box();

    void init(b2World* world,
              const glm::vec2& position,
              const glm::vec2& dimensions,
              PragmaEngine::GLTexture texture,
              PragmaEngine::ColorRGBA8 color,
              bool fixedRotation,
              glm::vec4 uvRect = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));

    void draw(PragmaEngine::SpriteBatch& spriteBatch);

    b2Body* getBody() const { return m_body; }
    b2Fixture* getFixture() const { return m_fixture; }
    const glm::vec2& getDimensions() const { return m_dimensions; }
    const PragmaEngine::ColorRGBA8& getColor() const { return m_color; }
private:
    glm::vec4 m_uvRect;
    b2Body* m_body = nullptr;
    b2Fixture* m_fixture = nullptr;
    glm::vec2 m_dimensions;
    PragmaEngine::ColorRGBA8 m_color;
    PragmaEngine::GLTexture m_texture;
};

