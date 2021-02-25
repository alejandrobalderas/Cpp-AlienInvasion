#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Sprite
{
public:
    Sprite(SDL_Renderer *renderer, std::string pathToImage);
    // virtual ~Sprite();
    SDL_Texture *texture;
    SDL_Rect rRect;
    bool markDelete{false};
    int shapeSize{10};
    enum movingDirection
    {
        right = 1,
        left = -1
    };

    void draw();
    virtual void update();

    SDL_Rect *getRect() { return &rRect; };
    int getYPos() { return rRect.y; };
    int getXPos() { return rRect.x; };
    int getWidth() { return rRect.w; };
    int getHeight() { return rRect.h; };
    void setXPos(int x);
    void setYPos(int y);
    void setShapeSize(int size);

    static bool checkForCollision(const Sprite *a, const Sprite *b);

private:
    std::string pathToImage;
    SDL_Renderer *renderer;
    // const std::shared_ptr<GameSettings> settings;

    void loadTexture();
    void loadDstrect();
};

#endif