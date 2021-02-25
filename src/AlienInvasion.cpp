
#include "SDL2/SDL.h"
#include "AlienInvasion.h"
#include <algorithm>
#include <thread>

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

void AlienInvasion::runGame()
{
    std::cout << "Starting game loop" << std::endl;
    while (!quitGame)
    {
        controller->handleInput(this);
        updateGame();
        draw();
    }
}

// Updates all images on screen
void AlienInvasion::updateGame()
{
    checkFleetEdges();
    moveObjects();
    checkForCollision();
    removeObjects();
}

void AlienInvasion::moveObjects()
{
    ship->update();
    for (auto &bullet : bullets)
        bullet->update();

    // Sequential update of aliens
    // for (auto &alien : aliens)
    //     alien->update();

    // Parallel update of aliens
    for (auto &alien : aliens)
        threads.emplace_back(std::thread([&alien] { alien->update(); }));
    std::for_each(threads.begin(), threads.end(), [](std::thread &t) {
        t.join();
    });
    threads.clear();
}

void AlienInvasion::checkForCollision()
{
    for (auto &alien : aliens)
    {
        if (Sprite::checkForCollision(alien.get(), ship.get()))
        {
            shipHit();
            break;
        }
        for (auto &bullet : bullets)
        {
            if (Sprite::checkForCollision(bullet.get(), alien.get()))
            {
                alien->markDelete = true;
                bullet->markDelete = true;
            }
        }
    }
}

void AlienInvasion::removeObjects()
{
    bullets.erase(
        std::remove_if(
            bullets.begin(), bullets.end(),
            [](auto &bullet) { return bullet->markDelete || bullet->getYPos() <= 0; }),
        bullets.end());
    // }
    aliens.erase(
        std::remove_if(
            aliens.begin(), aliens.end(),
            [](auto &alien) {
                return alien->markDelete;
            }),
        aliens.end());
    if (aliens.empty())
    {
        levelUp();
        restartGame();
    }
}

void AlienInvasion::draw()
{
    int frame_start = SDL_GetTicks();
    SDL_RenderClear(renderer->getSDLRenderer());
    renderer->renderBackground();
    ship->draw();
    for (auto &bullet : bullets)
        bullet->draw();
    for (auto &alien : aliens)
        alien->draw();
    SDL_RenderPresent(renderer->getSDLRenderer());
    int frame_end = SDL_GetTicks();
    applyDelayIfNeeded(frame_start, frame_end);
    // updateWindowTitle(frame_start, frame_end);
}

void AlienInvasion::updateWindowTitle(int frame_start, int frame_end)
{
    int frame_duration = frame_end - frame_start;
    std::string msg;
    if (frame_duration == 0)
    {
        msg = "FPS: 1000";
    }
    else
    {
        int fps = 1000 / frame_duration;
        msg = "FPS: " + std::to_string(fps);
    }
    renderer->updateWindowTitle(msg);
}

void AlienInvasion::applyDelayIfNeeded(int frame_start, int frame_end)
{
    int frame_duration = frame_end - frame_start;
    int target_duration = settings->screen->getTargetFrameDuration();
    if (frame_duration < target_duration)
    {
        SDL_Delay(settings->screen->getTargetFrameDuration() - frame_duration);
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

void AlienInvasion::shipHit()
{
    // Respond to the Ship being hit by Aliens
    restartGame();
    SDL_Delay(500);
}

void AlienInvasion::restartGame()
{
    // Remove all remaining objects and create new ones with their starting positions
    aliens.clear();
    bullets.clear();
    createFleet();
    ship->setInitialPos();
}

void AlienInvasion::levelUp()
{
    settings->alien->levelUp();
}