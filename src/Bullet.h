class AlienInvasion;

#ifndef BULLET_H
#define BULLET_H

#include <string>
#include <memory>
#include "SDL2/SDL.h"
#include "Settings.h"
// #include "AlienInvasion.h"

class Bullet
{
private:
    std::string pathToImage = "./images/bullet.png";
    SDL_Rect rRect;

public:
    // Bullet(std::shared_ptr<Settings> settings, std::shared_ptr<Renderer> renderer);
    Bullet(AlienInvasion *game);
};

#endif