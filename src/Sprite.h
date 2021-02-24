class AlienInvasion;

#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include "SDL2/SDL.h"

#include "AlienInvasion.h"

class Sprite
{
public:
    Sprite(AlienInvasion *game);
    SDL_Texture *texture;
    bool markDelete{false};
    int shapeSize{10};

    virtual void draw();
    virtual void update();

    SDL_Rect *getRect() { return &rRect; };
    int getYPos() { return rRect.y; };
    int getXPos() { return rRect.x; };
    int getWidth() { return rRect.w; };
    int getHeight() { return rRect.h; };

private:
    std::string pathToImage;
    SDL_Renderer *renderer;
    SDL_Rect rRect;
    const std::shared_ptr<Settings> settings;

    void loadTexture();
    void loadDstrect();
};

#endif