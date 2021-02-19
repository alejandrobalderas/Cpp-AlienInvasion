#ifndef RENDERER_H
#define RENDERER_H
#include <SDL2/SDL.h>
#include "Settings.h"
#include <memory>
#include "Ship.h"

class Renderer
{
public:
    Renderer(std::shared_ptr<Settings>);
    ~Renderer();
    void render();
    SDL_Renderer *getRenderer() { return sdl_renderer; }
    // void renderShip(Ship *ship);
    void renderShip();
    void renderBackground();

private:
    std::shared_ptr<Settings> _settings;

    SDL_Window *sdl_window;
    SDL_Surface *sdl_surface;
    SDL_Renderer *sdl_renderer;

    SDL_Surface *ship_surface;
};

#endif
