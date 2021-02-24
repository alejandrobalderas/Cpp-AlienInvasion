class AlienInvasion;
class GameSettings;
#ifndef ALIEN_H
#define ALIEN_H

#include <string>
#include "SDL2/SDL.h"
#include "Sprite.h"

class Alien : public Sprite
{
public:
    // Constructor
    Alien(AlienInvasion *game);

    // Variables
    // Functions
    void draw() override;
    void update() override;
    bool checkEdges();
    static void changeDirection();

private:
    // Variables
    SDL_Renderer *rR;
    static movingDirection currentDirection;

    AlienInvasion *game;
    GameSettings *settings;
    int screenWidth;
    int screenHeight;
};

#endif