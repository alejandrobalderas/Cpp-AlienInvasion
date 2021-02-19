#ifndef SHIP_H
#define SHIP_H

#include <string>
#include <SDL2/SDL_image.h>
#include <memory>
#include "Settings.h"

class Ship
{
private:
    std::string path_to_image = "../src/images/rocket.png";
    SDL_Surface *image;
    std::shared_ptr<Settings> _settings;
    // std::shared_ptr<Renderer> renderer;
    SDL_Rect rRect;

    int speed{100};

public:
    // Ship(std::shared_ptr<Renderer>);
    Ship(std::shared_ptr<Settings> &settings);
    // Ship(std::shared_ptr<Renderer>);
    SDL_Texture *ship_texture;
    void blitme();
    void draw(SDL_Renderer *sdl_renderer);
    void move(int dx = 0, int dy = 0);

    void getTexture(SDL_Renderer *rR);
};

#endif