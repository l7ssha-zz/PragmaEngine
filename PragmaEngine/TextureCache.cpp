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
#include "TextureCache.h"
#include "ImageLoader.h"
#include <iostream>

namespace PragmaEngine {

    TextureCache::TextureCache()
    {
    }

    TextureCache::~TextureCache()
    {
    }

    GLTexture TextureCache::getTexture(std::string texturePath) {

        //lookup the texture and see if its in the map
        auto mit = _textureMap.find(texturePath);

        //check if its not in the map
        if (mit == _textureMap.end()) {
            //Load the texture
            GLTexture newTexture = ImageLoader::loadPNG(texturePath);

            //Insert it into the map
            _textureMap.insert(make_pair(texturePath, newTexture));

            return newTexture;
        }
        return mit->second;
    }

}