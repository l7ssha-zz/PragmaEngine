#pragma once

#include <vector>
#include <fstream>

namespace PragmaEngine {

    class IOManager
    {
    public:
        static bool readFileToBuffer(std::string filePath, std::vector<unsigned char>& buffer);
    };

}