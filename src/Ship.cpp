#include <iostream>
#include "Ship.h"

Ship::Ship(AlienInvasion *game) : m_settings(game->settings), m_renderer(game->renderer)
{
    rR = m_renderer->getSDLRenderer();
    shapeSize = m_settings->ship->getShipShapeSize();
    loadTexture();
    loadDstrect();
}

void Ship::loadTexture()
{
    SDL_Surface *img = IMG_Load(pathToImage.c_str());
    shipTexture = SDL_CreateTextureFromSurface(rR, img);
    SDL_FreeSurface(img);
}

void Ship::loadDstrect()
{
    dstrect = {m_settings->screen->getScreenWidth() / 2 - shapeSize / 2,
               m_settings->screen->getScreenHeight() - shapeSize,
               shapeSize,
               shapeSize};
}

void Ship::draw()
{
    SDL_RenderCopy(rR, shipTexture, NULL, &dstrect);
}

void Ship::update()
{
    if (m_movingRight && dstrect.x < m_settings->screen->getScreenWidth() - dstrect.w)
        dstrect.x += m_settings->ship->getShipSpeed();
    if (m_movingLeft && dstrect.x > 0)
        dstrect.x -= m_settings->ship->getShipSpeed();
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
    x = dstrect.x + shapeSize / 2;
    y = dstrect.y;
}