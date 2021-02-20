//Forward declarations
class Ship;

#ifndef RENDERER_H
#define RENDERER_H
#include <SDL2/SDL.h>
#include <memory>
#include "Settings.h"
#include "Ship.h"

class Renderer
{
public:
    Renderer(const Settings *settings);
    ~Renderer();
    void render();
    SDL_Renderer *getSDLRenderer() const { return sdl_renderer; }
    void renderBackground();

    void tmp();

private:
    const Settings *settings;

    SDL_Window *sdl_window;
    SDL_Surface *sdl_surface;
    SDL_Renderer *sdl_renderer;

    SDL_Surface *ship_surface;

    void init();
};

#endif
