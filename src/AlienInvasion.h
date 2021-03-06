class Bullet;
class Controller;
class Alien;
#ifndef ALIENINVASION_H
#define ALIENINVASION_H

#include <iostream>
#include <memory>
#include <vector>
#include <thread>

#include "Renderer.h"
#include "Controller.h"
#include "Settings.h"
#include "Ship.h"
#include "Bullet.h"
#include "Alien.h"

class AlienInvasion
{
public:
    AlienInvasion();
    ~AlienInvasion();
    void runGame();
    void draw();
    void updateGame();
    void applyDelayIfNeeded(int, int);
    void fireBullet();
    std::shared_ptr<GameSettings> settings;
    std::shared_ptr<Renderer> renderer;
    std::unique_ptr<Controller> controller;

    std::shared_ptr<Ship> ship;
    std::vector<std::unique_ptr<Bullet>> bullets;

    bool quitGame = false;
    SDL_Event e;
    std::vector<std::thread> threads;

private:
    std::vector<std::unique_ptr<Alien>> aliens;

    void createFleet();
    void createAlien(int, int);
    void checkFleetEdges();
    void changeFleetDirection();
    void removeObjects();
    void checkForCollision();
    void moveObjects();
    void updateWindowTitle(int, int);
    void shipHit();
    void restartGame();
    void levelUp();
};

#endif