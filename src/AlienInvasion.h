#ifndef ALIENINVASION_H
#define ALIENINVASION_H

#include <iostream>
#include <Renderer.h>
#include <memory>
#include "Controller.h"
#include "Settings.h"
#include "Ship.h"

class AlienInvasion
{
public:
    AlienInvasion();
    ~AlienInvasion();
    void runGame();

private:
    bool quitGame = false;
    SDL_Event e;
    std::shared_ptr<Settings> settings;
    std::shared_ptr<Renderer> renderer;
    std::unique_ptr<Controller> controller;

    // std::unique_ptr<Ship> ship;
};

#endif