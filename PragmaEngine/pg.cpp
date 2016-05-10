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
#include <SDL/SDL.h>
#include <GL/glew.h>

#include "pg.h"

namespace PragmaEngine {

    int init() {
        //Initialize SDL
        SDL_Init(SDL_INIT_EVERYTHING);

        //Tell SDL that we want a double buffered window so we dont get
        //any flickering
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

        return 0;

    }

}