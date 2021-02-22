
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

    createFleet();

    // alien = std::make_unique<Alien>(this);
}

AlienInvasion::~AlienInvasion()
{
}

// Updates all images on screen
void AlienInvasion::updateScreen()
{
    ship->update();

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

    for (auto &alien : aliens)
    {
        alien->update();
    }
}

void AlienInvasion::draw()
{
    int frame_start = SDL_GetTicks();
    SDL_RenderClear(renderer->getSDLRenderer());
    renderer->renderBackground();
    ship->draw();
    for (auto &bullet : bullets)
    {
        bullet->draw();
    }
    for (auto &alien : aliens)
    {
        alien->draw();
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
    if (bullets.size() < settings->bullet->getMaxBullets())
        bullets.emplace_back(std::make_unique<Bullet>(this));
}

void AlienInvasion::createFleet()
{
    int alien_width = settings->alien->getShapeSize();
    float available_space_x = settings->getScreenWidth() - (2 * alien_width);
    int number_aliens_x = available_space_x / (1.7 * alien_width);

    // Create first row of aliens
    for (int i = 0; i < number_aliens_x; i++)
    {
        createAlien(i);
    }
}

void AlienInvasion::createAlien(int alienNumber)
{
    int alien_width = settings->alien->getShapeSize();
    std::unique_ptr<Alien> a = std::make_unique<Alien>(this);
    a->setXPos(alien_width + 2 * alien_width * alienNumber);
    aliens.emplace_back(std::move(a));
}