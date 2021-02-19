#ifndef ALIENINVASION_H
#define ALIENINVASION_H

#include <iostream>
#include <Renderer.h>
#include <memory>
#include "Controller.h"

class AlienInvasion
{
public:
    AlienInvasion();
    ~AlienInvasion();
    void runGame();

private:
    SDL_Event e;
    Renderer sdl_renderer{};
    Uint32 target_frame_duration = 1000 / 60;
    Controller controller;
};

#endif