#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>

#include "Vertex.h"

namespace PragmaEngine {

// Determines how we should sort the glyphs
enum class GlyphSortType {
    NONE,
    FRONT_TO_BACK,
    BACK_TO_FRONT,
    TEXTURE
};

// A glyph is a single quad. These are added via SpriteBatch::draw
class Glyph {
public:
    Glyph() {};
    Glyph(const glm::vec4& destRect, const glm::vec4& uvRect, GLuint Texture, float Depth, const ColorRGBA8& color) : 
        texture(Texture),
        depth(Depth) {
       
        topLeft.color = color;
        topLeft.setPosition(destRect.x, destRect.y + destRect.w);
        topLeft.setUV(uvRect.x, uvRect.y + uvRect.w);

        bottomLeft.color = color;
        bottomLeft.setPosition(destRect.x, destRect.y);
        bottomLeft.setUV(uvRect.x, uvRect.y);

        bottomRight.color = color;
        bottomRight.setPosition(destRect.x + destRect.z, destRect.y);
        bottomRight.setUV(uvRect.x + uvRect.z, uvRect.y);

        topRight.color = color;
        topRight.setPosition(destRect.x + destRect.z, destRect.y + destRect.w);
        topRight.setUV(uvRect.x + uvRect.z, uvRect.y + uvRect.w);
    }

    GLuint texture;
    float depth;
    
    Vertex topLeft;
    Vertex bottomLeft;
    Vertex topRight;
    Vertex bottomRight;
};

// Each render batch is used for a single draw call
class RenderBatch {
public:
    RenderBatch(GLuint Offset, GLuint NumVertices, GLuint Texture) : offset(Offset),
        numVertices(NumVertices), texture(Texture) {
    }
    GLuint offset;
    GLuint numVertices;
    GLuint texture;
};

// The SpriteBatch class is a more efficient way of drawing sprites
class SpriteBatch
{
public:
    SpriteBatch();
    ~SpriteBatch();

    // Initializes the spritebatch
    void init();

    // Begins the spritebatch
    void begin(GlyphSortType sortType = GlyphSortType::TEXTURE);

    // Ends the spritebatch
    void end();

    // Adds a glyph to the spritebatch
    void draw(const glm::vec4& destRect, const glm::vec4& uvRect, GLuint texture, float depth, const ColorRGBA8& color);

    // Renders the entire SpriteBatch to the screen
    void renderBatch();

private:
    // Creates all the needed RenderBatches
    void createRenderBatches();

    // Generates our VAO and VBO
    void createVertexArray();

    // Sorts glyphs according to _sortType
    void sortGlyphs();

    // Comparators used by sortGlyphs()
    static bool compareFrontToBack(Glyph* a, Glyph* b);
    static bool compareBackToFront(Glyph* a, Glyph* b);
    static bool compareTexture(Glyph* a, Glyph* b);

    GLuint _vbo;
    GLuint _vao;

    GlyphSortType _sortType;

    std::vector<Glyph*> _glyphPointers; ///< This is for sorting
    std::vector<Glyph> _glyphs; ///< These are the actual glyphs
    std::vector<RenderBatch> _renderBatches;
};

}