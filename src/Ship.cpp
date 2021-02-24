#include <iostream>
#include "Ship.h"

Ship::Ship(AlienInvasion *game) : settings(game->settings), renderer(game->renderer)
{
    rR = renderer->getSDLRenderer();
    shapeSize = settings->ship->getShipShapeSize();
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
    dstrect = {settings->screen->getScreenWidth() / 2 - shapeSize / 2,
               settings->screen->getScreenHeight() - shapeSize,
               shapeSize,
               shapeSize};
}

void Ship::draw()
{
    SDL_RenderCopy(rR, shipTexture, NULL, &dstrect);
}

void Ship::update()
{
    if (m_movingRight && dstrect.x < settings->screen->getScreenWidth() - dstrect.w)
        dstrect.x += settings->ship->getShipSpeed();
    if (m_movingLeft && dstrect.x > 0)
        dstrect.x -= settings->ship->getShipSpeed();
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