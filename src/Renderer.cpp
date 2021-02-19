#include <iostream>
#include <Renderer.h>

Renderer::Renderer() : Renderer(640, 480){};
Renderer::Renderer(int screen_width, int screen_height) : SCREEN_WIDTH(screen_width), SCREEN_HEIGHT(screen_height)
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
                                      SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,
                                      SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
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
};
Renderer::~Renderer()
{
    SDL_DestroyWindow(sdl_window);
    SDL_Quit();
}

void Renderer::render()
{
    // Clear screen
    // SDL_SetRenderDrawColor(sdl_renderer, 20, 20, 20, 255);
    SDL_SetRenderDrawColor(sdl_renderer, cBackgroundR, cBackgroundG, cBackgroundB, cBackgroundAlpha);

    SDL_RenderClear(sdl_renderer);
    SDL_RenderPresent(sdl_renderer);
    // SDL_Delay(2000);
}
