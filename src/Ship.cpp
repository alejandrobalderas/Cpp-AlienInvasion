#include <iostream>
#include "Ship.h"
#include "AlienInvasion.h"

Ship::Ship(AlienInvasion *game)
    : game(game),
      rR(game->renderer->getSDLRenderer()),
      Sprite(game->renderer->getSDLRenderer(), game->settings->ship->getImagePath())
{
    settings = game->settings.get();
    screenWidth = settings->screen->getScreenWidth();
    screenHeight = settings->screen->getScreenHeight();
    setShapeSize(settings->ship->getShapeSize());
    setInitialPos();
}
Ship::~Ship()
{
}

void Ship::setInitialPos()
{
    setXPos(screenWidth / 2);
    setYPos(screenHeight - shapeSize);
}

void Ship::draw()
{
    SDL_RenderCopy(rR, texture, NULL, &rRect);
}

void Ship::update()
{
    if (m_movingRight && rRect.x < settings->screen->getScreenWidth() - rRect.w)
        rRect.x += settings->ship->getShipSpeed();
    if (m_movingLeft && rRect.x > 0)
        rRect.x -= settings->ship->getShipSpeed();
}

void Ship::moveLeft()
{
    m_movingLeft = true;
}

void Ship::moveRight()
{
    m_movingRight = true;
}

void Ship::stopMovingRight()
{
    m_movingRight = false;
}

void Ship::stopMovingLeft()
{
    m_movingLeft = false;
}

void Ship::getShipPositionForBullet(int &x, int &y) const
{
    x = rRect.x + rRect.w / 2 - settings->bullet->getShapeSize() / 4;
    y = rRect.y;
}
