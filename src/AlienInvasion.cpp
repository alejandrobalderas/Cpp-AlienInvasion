
#include "SDL2/SDL.h"
#include "AlienInvasion.h"
#include <algorithm>

AlienInvasion::AlienInvasion()
{
    settings = std::make_shared<Settings>();
    renderer = std::make_shared<Renderer>(settings);
    ship = std::make_shared<Ship>(this);
    // bullet = std::make_shared<Bullet>(this);
    controller = std::make_unique<Controller>();
}

AlienInvasion::~AlienInvasion()
{
}

// Updates all images on screen
void AlienInvasion::updateScreen()
{
    ship->update();

    // bullet->update();
    // remove bullets that are out of range
    bullets.erase(
        std::remove_if(
            bullets.begin(), bullets.end(),
            [](const auto &b) {
                return b->getYPos() <= 0;
            }),
        bullets.end());

    for (auto &bullet : bullets)
    {
        bullet->update();
    }
}

void AlienInvasion::draw()
{
    int frame_start = SDL_GetTicks();
    SDL_RenderClear(renderer->getSDLRenderer());
    renderer->renderBackground();
    ship->draw();
    // bullet->draw();
    for (auto &bullet : bullets)
    {
        bullet->draw();
    }

    SDL_RenderPresent(renderer->getSDLRenderer());
    int frame_end = SDL_GetTicks();
    applyDelayIfNeeded(frame_start, frame_end);
}

void AlienInvasion::applyDelayIfNeeded(int frame_start, int frame_end)
{
    int frame_duration = frame_end - frame_start;
    if (frame_duration < settings->getTargetFrameDuration())
    {
        SDL_Delay(settings->getTargetFrameDuration() - frame_duration);
    }
}

void AlienInvasion::runGame()
{
    std::cout << "Starting game loop" << std::endl;
    while (!quitGame)
    {
        // controller->handleInput(&e, ship, quitGame);
        controller->handleInput(this);
        updateScreen();
        draw();
    }
}

void AlienInvasion::fireBullet()
{
    bullets.emplace_back(std::make_unique<Bullet>(this));
}