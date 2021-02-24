class AlienInvasion;
#ifndef ALIEN_H
#define ALIEN_H

#include <string>
#include "SDL2/SDL.h"
#include "AlienInvasion.h"

class Alien
{
public:
    // Constructor
    Alien(AlienInvasion *game);

    // Variables
    SDL_Rect *getRect() { return &rRect; };
    bool markDelete{false};

    // Functions
    bool checkEdges();
    static void changeDirection();
    void draw();
    void update();
    // Getters / Setters
    int getBottomEdge();
    int getYPos();
    void setXPos(int x);
    void setYPos(int y);
    void returnLeftRightEdges(int &, int &);
    void returnTopBottomEdges(int &, int &);

private:
    enum direction
    {
        right = 1,
        left = -1
    };
    // Variables
    std::string pathToImage = "./images/ufo.png";
    int shapeSize;
    SDL_Rect rRect;
    SDL_Renderer *rR;
    SDL_Texture *texture;
    static direction currentDir;
    AlienInvasion *m_game;

    void loadTexture();
    void loadDstrect();
};

#endif