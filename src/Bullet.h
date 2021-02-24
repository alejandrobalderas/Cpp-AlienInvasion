class AlienInvasion;

#ifndef BULLET_H
#define BULLET_H

#include <string>
#include <memory>
#include "SDL2/SDL.h"
#include "Settings.h"
#include "AlienInvasion.h"

class Bullet
{
public:
    // Constructor
    Bullet(AlienInvasion *game);

    // Variables
    SDL_Texture *bulletTexture;
    SDL_Rect *getRect() { return &rRect; };
    bool markDelete{false};

    // Methods
    void draw();
    void update();
    // Getters / Setters
    int getYPos() { return rRect.y; };
    void returnLeftRightEdges(int &topLeft, int &topRight);
    void returnTopBottomEdges(int &top, int &bottom);

private:
    // Variables
    std::string pathToImage = "./images/bullet.png";
    SDL_Rect rRect;
    const Ship *m_ship;
    const std::shared_ptr<Settings> m_settings;
    std::shared_ptr<Renderer> m_renderer;
    SDL_Renderer *rR;

    // Functions
    void loadTexture();
    void loadDstrect();
};

#endif