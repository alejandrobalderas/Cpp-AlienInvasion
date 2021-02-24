
#include "SDL2/SDL.h"
#include "AlienInvasion.h"
#include <algorithm>

AlienInvasion::AlienInvasion()
{
    settings = std::make_shared<GameSettings>();
    renderer = std::make_shared<Renderer>(settings);
    ship = std::make_shared<Ship>(this);
    controller = std::make_unique<Controller>();

    createFleet();
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
    for (auto &bullet : bullets)
    {
        for (auto &alien : aliens)
        {
            if (Sprite::checkForCollision(bullet.get(), alien.get()))
            {
                alien->markDelete = true;
                bullet->markDelete = true;
            }
        }
    }

    if (!bullets.empty())
    {
        bullets.erase(
            std::remove_if(
                bullets.begin(), bullets.end(),
                [](auto &bullet) { return bullet->markDelete; }),
            bullets.end());
    }
    aliens.erase(
        std::remove_if(
            aliens.begin(), aliens.end(),
            [](auto &alien) {
                return alien->markDelete;
            }),
        aliens.end());

    checkFleetEdges();
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
    if (frame_duration < settings->screen->getTargetFrameDuration())
    {
        SDL_Delay(settings->screen->getTargetFrameDuration() - frame_duration);
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
    {
        int x, y;
        ship->getShipPositionForBullet(x, y);
        bullets.emplace_back(std::make_unique<Bullet>(x, y, this));
    }
}

void AlienInvasion::createFleet()
{
    int alienShape = settings->alien->getShapeSize();
    float available_space_x = settings->screen->getScreenWidth() - (2 * alienShape);
    int number_aliens_x = available_space_x / (2 * alienShape);

    int shipSize = settings->ship->getShapeSize();
    float available_space_y = settings->screen->getScreenHeight() - 3 * alienShape - shipSize;
    int number_rows = available_space_y / (2 * alienShape);

    // Create full fleat
    for (int rowNum = 0; rowNum < settings->alien->getMaxRowNumInFleet(); rowNum++)
    {
        for (int colNum = 0; colNum < number_aliens_x; colNum++)
        {
            createAlien(colNum, rowNum);
        }
    }
}

void AlienInvasion::createAlien(int alienNumber, int rowNum)
{
    int alienShape = settings->alien->getShapeSize();
    std::unique_ptr<Alien> a = std::make_unique<Alien>(this);
    a->setXPos(alienShape + 2 * alienShape * alienNumber);
    a->setYPos(alienShape + 2 * alienShape * rowNum);
    aliens.emplace_back(std::move(a));
}

void AlienInvasion::checkFleetEdges()
{
    for (auto &a : aliens)
    {
        if (a->checkEdges())
        {
            changeFleetDirection();
            break;
        }
    }
}

void AlienInvasion::changeFleetDirection()
{
    for (auto &a : aliens)
    {
        a->setYPos(a->getYPos() + settings->alien->getDropSpeed());
    }
    Alien::changeDirection();
}

bool AlienInvasion::checkAlienBulletCollision(SDL_Rect *alien, SDL_Rect *bullet)
{
    bool x_collision = (bullet->x > alien->x && bullet->x + bullet->w < alien->x + alien->w);
    bool y_collision = (bullet->y < alien->y + alien->h && bullet->y + bullet->h > alien->y);
    if (x_collision && y_collision)
    {
        return true;
    }
    else
    {
        return false;
    }
}
