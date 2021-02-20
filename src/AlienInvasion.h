class Bullet;
class Controller;
#ifndef ALIENINVASION_H
#define ALIENINVASION_H

#include <iostream>
#include <memory>
#include "Renderer.h"
#include "Controller.h"
#include "Settings.h"
#include "Ship.h"
#include "Bullet.h"

class AlienInvasion
{
public:
    AlienInvasion();
    ~AlienInvasion();
    void runGame();
    void draw();
    void updateScreen();
    void applyDelayIfNeeded(int, int);
    std::shared_ptr<Settings> settings;
    std::shared_ptr<Renderer> renderer;
    std::unique_ptr<Controller> controller;

    std::shared_ptr<Ship> ship;
    std::shared_ptr<Bullet> bullet;

private:
    bool quitGame = false;
    SDL_Event e;
};

#endif