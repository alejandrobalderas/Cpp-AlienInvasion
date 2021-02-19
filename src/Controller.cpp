#include <iostream>
#include "Controller.h"

void Controller::handleInput(SDL_Event *e, std::shared_ptr<Ship> ship, bool &quit)
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
                ship->move(-1, 0);
                break;

            case SDLK_RIGHT:
                std::cout << "Right" << std::endl;
                ship->move(1, 0);
                break;
            }
        }
    }
}
