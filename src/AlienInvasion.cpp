
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
    int alienShape = settings->alien->getShapeSize();
    float available_space_x = settings->getScreenWidth() - (2 * alienShape);
    int number_aliens_x = available_space_x / (2 * alienShape);

    int shipSize = settings->getShipShapeSize();
    float available_space_y = settings->getScreenHeight() - 3 * alienShape - shipSize;
    int number_rows = available_space_y / (2 * alienShape);

    // Create full fleat
    for (int rowNum = 0; rowNum < settings->alien->getMaxRowNumInFleet(); rowNum++)
    {
        for (int colNum = 0; colNum < number_aliens_x; colNum++)
        {
            createAlien(colNum, rowNum);
        }
    }
    // Create first row of aliens
}

void AlienInvasion::createAlien(int alienNumber, int rowNum)
{
    int alienShape = settings->alien->getShapeSize();
    std::unique_ptr<Alien> a = std::make_unique<Alien>(this);
    a->setXPos(alienShape + 2 * alienShape * alienNumber);
    a->setYPos(alienShape + 2 * alienShape * rowNum);
    aliens.emplace_back(std::move(a));
}