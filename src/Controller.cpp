#include <iostream>
#include "Controller.h"

void Controller::handleInput(SDL_Event *e, std::shared_ptr<Ship> ship, bool &quit)
{
    while (SDL_PollEvent(e))
    {
        if (e->type == SDL_QUIT)
        {
            quit = true;
            break;
        }
        else if (e->type == SDL_KEYDOWN)
        {
            switch (e->key.keysym.sym)
            {
            case SDLK_q:
                std::cout << "q" << std::endl;
                quit = true;
                break;

            case SDLK_LEFT:
                std::cout << "Left" << std::endl;
                ship->moveLeft();
                break;

            case SDLK_RIGHT:
                std::cout << "Right" << std::endl;
                ship->moveRight();
                break;
            }
        }
        else if (e->type == SDL_KEYUP)
        {
            switch (e->key.keysym.sym)
            {
            case SDLK_LEFT:
            case SDLK_RIGHT:
                std::cout << "Stop moving" << std::endl;
                ship->stopMoving();
                break;
            }
        }
    }
}
