#include <iostream>
#include "Controller.h"

void Controller::handleInput(SDL_Event *e, std::unique_ptr<Ship> &ship, bool &quit)
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
            checkKeyDown(e, ship, quit);
        }
        else if (e->type == SDL_KEYUP)
        {
            checkKeyUp(e, ship, quit);
        }
    }
}

void Controller::checkKeyDown(SDL_Event *e, std::unique_ptr<Ship> &ship, bool &quit)
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

    case SDLK_SPACE:
        std::cout << "Space" << std::endl;
        break;
    }
}
void Controller::checkKeyUp(SDL_Event *e, std::unique_ptr<Ship> &ship, bool &quit)
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