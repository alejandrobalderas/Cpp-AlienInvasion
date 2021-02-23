class AlienInvasion;
#ifndef ALIEN_H
#define ALIEN_H

#include <string>
#include "SDL2/SDL.h"
#include "AlienInvasion.h"

class Alien
{
private:
    std::string pathToImage = "./images/ufo.png";

    SDL_Rect rRect;
    SDL_Renderer *rR;
    SDL_Texture *texture;

    int shapeSize;

    void loadTexture();
    void loadDstrect();

    enum direction
    {
        right = 1,
        left = -1
    };
    static direction currentDir;

    AlienInvasion *m_game;

public:
    Alien(AlienInvasion *game);
    int getYPos();
    void setXPos(int x);
    void setYPos(int y);
    bool checkEdges();
    void draw();
    void update();
    static void changeDirection();
};

#endif