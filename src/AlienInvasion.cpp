
#include <iostream>
#include <SDL.h>

#include "AlienInvasion.h"

AlienInvasion::AlienInvasion()
{
    settings = std::make_shared<Settings>();
    renderer = std::make_shared<Renderer>(settings);
    ship = std::make_unique<Ship>(settings);
    ship->getTexture(renderer->getSDLRenderer());
    controller = std::make_unique<Controller>();
}

AlienInvasion::~AlienInvasion()
{
}

// Updates all images on screen
void AlienInvasion::updateScreen()
{
    int frame_start = SDL_GetTicks();

    SDL_RenderClear(renderer->getSDLRenderer());
    renderer->renderBackground();
    renderer->renderShip(ship);
    SDL_RenderPresent(renderer->getSDLRenderer());

    int frame_end = SDL_GetTicks();

    applyDelayIfNeeded(frame_start, frame_end);
}

void AlienInvasion::applyDelayIfNeeded(int frame_start, int frame_end)
{
    int frame_duration = frame_end - frame_start;
    if (frame_duration < settings->getTargetFrameDuration())
    {
        SDL_Delay(settings->getTargetFrameDuration() - frame_duration);
    }
}

void AlienInvasion::runGame()
{
    std::cout << "Starting game loop" << std::endl;
    while (!quitGame)
    {
        controller->handleInput(&e, quitGame);
        //Render here
        updateScreen();
    }
}