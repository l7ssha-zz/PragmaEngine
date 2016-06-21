#include "Errors.h"
#include <iostream>
#include <SDL/SDL.h>

namespace PragmaEngine {

    //Prints out an error message and exits the game
    void fatalError(std::string errorString) {
        std::cout << errorString << std::endl;
      
		system("PAUSE");
        SDL_Quit();
        exit(69);
    }

}