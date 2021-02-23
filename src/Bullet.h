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
private:
    std::string pathToImage = "./images/bullet.png";
    SDL_Rect rRect;
    const Ship *m_ship;
    const std::shared_ptr<Settings> m_settings;
    std::shared_ptr<Renderer> m_renderer;
    SDL_Renderer *rR;

    void loadTexture();
    void loadDstrect();

public:
    Bullet(AlienInvasion *game);
    void draw();
    void update();
    int getYPos() { return rRect.y; };
    void returnLeftRightEdges(int &topLeft, int &topRight);
    void returnTopBottomEdges(int &top, int &bottom);
    SDL_Texture *bulletTexture;
    SDL_Rect *getRect() { return &rRect; };
    bool markDelete{false};
};

#endif