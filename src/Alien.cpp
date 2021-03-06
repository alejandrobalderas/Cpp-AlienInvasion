#include "Alien.h"
#include "AlienInvasion.h"

Alien::movingDirection Alien::currentDirection = right;
Alien::Alien(AlienInvasion *game)
    : game(game),
      rR(game->renderer->getSDLRenderer()),
      Sprite(game->renderer->getSDLRenderer(), game->settings->alien->getImagePath())
{
    settings = game->settings.get();
    screenWidth = settings->screen->getScreenWidth();
    screenHeight = settings->screen->getScreenHeight();
    setShapeSize(settings->alien->getShapeSize());
    speed = settings->alien->getSpeed();
}

void Alien::update()
{
    rRect.x += (speed * currentDirection);
}

bool Alien::checkEdges()
{
    if (rRect.x > settings->screen->getScreenWidth() - shapeSize || rRect.x < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Alien::changeDirection()
{
    currentDirection = (currentDirection == left ? right : left);
}

void Alien::levelUp()
{
    speed += 10;
}