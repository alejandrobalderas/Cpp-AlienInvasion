#include "Controller.h"
#include <iostream>

void Controller::handleInput(SDL_Event *e, bool &quit)
{
    while (SDL_PollEvent(e))
    {
        if (e->type == SDL_QUIT)
        {
            quit = true;
            std::cout << "q" << std::endl;
            break;
        }
        else if (e->type == SDL_KEYDOWN)
        {
            switch (e->key.keysym.sym)
            {
            case SDLK_q:
                std::cout << "q" << std::endl;
                break;

            case SDLK_UP:
                std::cout << "Up" << std::endl;
                break;

            case SDLK_DOWN:
                std::cout << "Down" << std::endl;
                break;

            case SDLK_LEFT:
                std::cout << "Left" << std::endl;
                break;

            case SDLK_RIGHT:
                std::cout << "Right" << std::endl;
                break;
            }
        }
    }
}
