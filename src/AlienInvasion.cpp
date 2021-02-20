
#include <iostream>
#include <SDL.h>

#include "AlienInvasion.h"

AlienInvasion::AlienInvasion()
{
    settings = std::make_unique<Settings>();
    renderer = std::make_unique<Renderer>(settings.get());
    ship = std::make_unique<Ship>(settings.get(), renderer.get());
    controller = std::make_unique<Controller>();
}

AlienInvasion::~AlienInvasion()
{
}

// Updates all images on screen
void AlienInvasion::updateScreen()
{
    ship->update();
}

void AlienInvasion::draw()
{
    int frame_start = SDL_GetTicks();
    SDL_RenderClear(renderer->getSDLRenderer());
    renderer->renderBackground();
    ship->draw();
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
        controller->handleInput(&e, ship, quitGame);
        updateScreen();
        draw();
    }
}