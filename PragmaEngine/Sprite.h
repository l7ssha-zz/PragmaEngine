/*
------------------------- PragmaEngine BY L7SSHA | ALL RIGTS RESERVED -------------------------
PragamEngine version 2.0
Copyright (c) 2016 Szymon "l7ssha" Uglis

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to no one to use this software for any purpose,
including commercial application

------------------------- PragmaEngine BY L7SSHA | ALL RIGTS RESERVED -------------------------
*/

#pragma once

#include "GLTexture.h"
#include "Vertex.h"
#include "ResourceManager.h"

#include <cstddef>
#include <string>
#include <GL/glew.h>

namespace PragmaEngine {

    //A 2D quad that can be rendered to the screen
    class Sprite
    {
    public:
        Sprite();
        ~Sprite();

        void init(float x, float y, float width, float height, std::string texturePath);

        void draw();

        //private:
        float _x;
        float _y;
        float _width;
        float _height;
        GLuint _vboID;
        GLTexture _texture;

    };

}