
#include <iostream>
#include <AlienInvasion.h>
#include <SDL.h>
#include "Renderer.h"

AlienInvasion::AlienInvasion()
{
    controller = Controller();
}

AlienInvasion::~AlienInvasion()
{
}

void AlienInvasion::runGame()
{

    SDL_Event e;
    bool quit = false;
    Uint32 frame_start;
    Uint32 frame_end;
    Uint32 frame_duration;

    std::cout << "Starting game loop" << std::endl;
    while (!quit)
    {
        frame_start = SDL_GetTicks();
        controller.handleInput(&e, quit);
        sdl_renderer.render();

        frame_end = SDL_GetTicks();
        frame_duration = frame_end - frame_start;
        if (frame_duration < target_frame_duration)
        {
            SDL_Delay(target_frame_duration - frame_duration);
        }
    }
}