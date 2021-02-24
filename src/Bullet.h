class AlienInvasion;
class GameSettings;

#ifndef BULLET_H
#define BULLET_H

#include <string>
#include <memory>
#include "SDL2/SDL.h"
#include "AlienInvasion.h"

class Bullet : public Sprite
{
public:
    // Constructor
    Bullet(int x, int y, AlienInvasion *game);

    // Variables
    // Methods
    void draw() override;
    void update() override;
    // Getters / Setters

private:
    // Variables
    SDL_Renderer *rR;
    AlienInvasion *game;
    GameSettings *settings;
    int bulletSpeed;
    int screenWidth;
    int screenHeight;
};

#endif