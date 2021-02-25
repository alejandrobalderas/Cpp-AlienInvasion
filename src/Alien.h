class AlienInvasion;
class GameSettings;
#ifndef ALIEN_H
#define ALIEN_H

#include <string>
#include "SDL2/SDL.h"
#include "Sprite.h"
#include <thread>
#include <vector>

class Alien : public Sprite
{
public:
    // Constructor
    Alien(AlienInvasion *game);

    // Variables
    // Functions
    void update() override;
    bool checkEdges();
    static void changeDirection();
    std::vector<std::thread> threads;
    void levelUp();

private:
    // Variables
    SDL_Renderer *rR;
    static movingDirection currentDirection;

    AlienInvasion *game;
    GameSettings *settings;
    int screenWidth;
    int screenHeight;
    int speed;
};

#endif