#include <iostream>
#include "Renderer.h"

Renderer::Renderer(const std::shared_ptr<GameSettings> settings) : settings(settings)
{
    init();
};
Renderer::~Renderer()
{
    SDL_DestroyWindow(sdl_window);
    SDL_Quit();
}

void Renderer::init()
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
                                      SDL_WINDOWPOS_CENTERED, settings->screen->getScreenWidth(),
                                      settings->screen->getScreenHeight(), SDL_WINDOW_SHOWN);
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
}

void Renderer::renderBackground()
{
    int BackgroundR{0};
    int BackgroundG{0};
    int BackgroundB{0};
    int BackgroundA{0};
    settings->screen->getBackgroundColors(BackgroundR, BackgroundG, BackgroundB, BackgroundA);
    SDL_SetRenderDrawColor(sdl_renderer, BackgroundR, BackgroundG, BackgroundB, BackgroundA);
}

void Renderer::updateWindowTitle(std::string msg)
{
    SDL_SetWindowTitle(sdl_window, msg.c_str());
}