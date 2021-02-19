#ifndef RENDERER_H
#define RENDERER_H
#include <SDL2/SDL.h>

class Renderer
{
public:
    Renderer();
    Renderer(int screen_width, int screen_height);
    ~Renderer();
    void render();

private:
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    SDL_Window *sdl_window;
    SDL_Surface *sdl_surface;
    SDL_Renderer *sdl_renderer;

    int cBackgroundR{20};
    int cBackgroundG{20};
    int cBackgroundB{50};
    int cBackgroundAlpha{255};
};

#endif
