class AlienInvasion;

#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include "SDL2/SDL.h"

#include "AlienInvasion.h"

class Sprite
{
public:
    Sprite(AlienInvasion *game, SpriteSettings *settings);
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
    void setXPos(int x);
    void setYPos(int y);

private:
    enum movingDirection
    {
        right = 1,
        left = -1
    };
    std::string pathToImage;
    SDL_Renderer *renderer;
    SDL_Rect rRect;
    const std::shared_ptr<GameSettings> settings;

    void loadTexture();
    void loadDstrect();
};

#endif