
#include <iostream>
#include <AlienInvasion.h>
#include <SDL.h>
#include "Renderer.h"
#include "Settings.h"
// #include "Ship.h"

AlienInvasion::AlienInvasion()
{
    settings = std::make_shared<Settings>();
    renderer = std::make_shared<Renderer>(settings);
    controller = std::make_unique<Controller>();
    // ship = std::make_unique<Ship>(renderer);
}

AlienInvasion::~AlienInvasion()
{
}

void AlienInvasion::runGame()
{

    int frame_start;
    int frame_end;
    int frame_duration;
    int target_frame_duration = settings->getTargetFrameDuration();

    std::cout << "Starting game loop" << std::endl;
    while (!quitGame)
    {
        frame_start = SDL_GetTicks();

        controller->handleInput(&e, quitGame);
        renderer->render();

        frame_end = SDL_GetTicks();
        frame_duration = frame_end - frame_start;
        if (frame_duration < target_frame_duration)
        {
            SDL_Delay(target_frame_duration - frame_duration);
        }
    }
}