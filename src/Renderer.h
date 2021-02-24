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
    // Constructor
    Renderer(const std::shared_ptr<Settings> settings);
    ~Renderer();
    // Variables
    SDL_Renderer *getSDLRenderer() const { return sdl_renderer; }

    // Methods
    void renderBackground();

private:
    // Variables
    std::shared_ptr<Settings> settings;
    SDL_Window *sdl_window;
    SDL_Surface *sdl_surface;
    SDL_Renderer *sdl_renderer;

    // Methods
    void init();
};

#endif
