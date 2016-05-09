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
#include "Errors.h"

#include <cstdlib>

#include <iostream>
#include <SDL/SDL.h>

namespace PragmaEngine {

    //Prints out an error message and exits the game
    void fatalError(std::string errorString) {
        std::cout << errorString << std::endl;
        std::cout << "Enter any key to quit...";
        
		int tmp;
        std::cin >> tmp;
        SDL_Quit();
        exit(69);
    }

}