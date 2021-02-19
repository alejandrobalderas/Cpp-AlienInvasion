#include <iostream>
#include <Renderer.h>
#include <Ship.h>

#include "SDL2/SDL_image.h"

Renderer::Renderer(std::shared_ptr<Settings> settings) : settings(settings)
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "SDL could not initialize.\n";
        std::cerr << "SDL_Errors: " << SDL_GetError() << std::endl;
    }
    else
    {
        sdl_window = SDL_CreateWindow("Alien Invasion", SDL_WINDOWPOS_CENTERED,
                                      SDL_WINDOWPOS_CENTERED, settings->getScreenWidth(),
                                      settings->getScreenHeight(), SDL_WINDOW_SHOWN);
        if (sdl_window == NULL)
        {
            std::cerr << "Window could not be created.\n";
            std::cerr << "SDL_Errors: " << SDL_GetError() << std::endl;
        }
        else
        {
            // Create renderer
            sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
            if (sdl_renderer == nullptr)
            {
                std::cerr << "Render could not be created" << std::endl;
            }
        }
    }

    // Load ship
    ship_surface = IMG_Load("../src/images/rocket.png");
};
Renderer::~Renderer()
{
    SDL_DestroyWindow(sdl_window);
    SDL_Quit();
}

void Renderer::renderShip()
{
    SDL_Texture *texture = SDL_CreateTextureFromSurface(sdl_renderer, ship_surface);
    // SDL_Rect dstrect = {10, 10, 100, 100};
    int SHAPE_SIZE = 60;
    SDL_Rect dstrect = {settings->getScreenWidth() / 2 - SHAPE_SIZE / 2, settings->getScreenHeight() - SHAPE_SIZE, SHAPE_SIZE, SHAPE_SIZE};
    SDL_RenderCopy(sdl_renderer, texture, NULL, &dstrect);
}

// void Renderer::renderShip(Ship *ship)
// {
// }

void Renderer::renderBackground()
{
    int BackgroundR{0};
    int BackgroundG{0};
    int BackgroundB{0};
    int BackgroundA{0};
    settings->getBackgroundColors(BackgroundR, BackgroundG, BackgroundB, BackgroundA);
    SDL_SetRenderDrawColor(sdl_renderer, BackgroundR, BackgroundG, BackgroundB, BackgroundA);
}

void Renderer::render()
{
    // Clear screen
    SDL_RenderClear(sdl_renderer);

    renderBackground();
    renderShip();

    SDL_RenderPresent(sdl_renderer);
}
