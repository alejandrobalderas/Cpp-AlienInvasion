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

    AlienInvasion *m_game;

public:
    Alien(AlienInvasion *game);
    void setXPos(int x);
    void draw();
    void update();
};

#endif