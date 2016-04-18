#pragma once

#include "GLTexture.h"
#include "picoPNG.h"
#include "IOManager.h"
#include "Errors.h"

#include <string>

namespace PragmaEngine {

    //Loads images into GLTextures
    class ImageLoader
    {
    public:
        static GLTexture loadPNG(std::string filePath);
    };

}