#include <iostream>
#include "Controller.h"

void Controller::handleInput(AlienInvasion *game)
{
    SDL_Event *e = &game->e;
    while (SDL_PollEvent(e))
    {
        if (e->type == SDL_QUIT)
        {
            game->quitGame = true;
            break;
        }
        else if (e->type == SDL_KEYDOWN)
        {
            checkKeyDown(game);
        }
        else if (e->type == SDL_KEYUP)
        {
            checkKeyUp(game);
        }
    }
}

void Controller::checkKeyDown(AlienInvasion *game)
{
    switch (game->e.key.keysym.sym)
    {
    case SDLK_q:
        std::cout << "q" << std::endl;
        game->quitGame = true;
        break;

    case SDLK_LEFT:
        std::cout << "Left" << std::endl;
        game->ship->moveLeft();
        break;

    case SDLK_RIGHT:
        std::cout << "Right" << std::endl;
        game->ship->moveRight();
        break;

    case SDLK_SPACE:
        std::cout << "Space" << std::endl;
        game->fireBullet();
        break;
    }
}

void Controller::checkKeyUp(AlienInvasion *game)
{
    switch (game->e.key.keysym.sym)
    {
    case SDLK_LEFT:
    case SDLK_RIGHT:
        std::cout << "Stop moving" << std::endl;
        game->ship->stopMoving();
        break;
    }
}