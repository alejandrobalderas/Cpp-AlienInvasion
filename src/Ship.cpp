
#include <iostream>
#include "Ship.h"

Ship::Ship(const Settings *settings, Renderer *renderer) : m_settings(settings), m_renderer(renderer)
{
    rR = m_renderer->getSDLRenderer();
    loadTexture();
    loadDstrect();
}

void Ship::loadTexture()
{
    SDL_Surface *img = IMG_Load(path_to_image.c_str());
    ship_texture = SDL_CreateTextureFromSurface(rR, img);
    SDL_FreeSurface(img);
}

void Ship::loadDstrect()
{
    int shape_size = m_settings->getShipShapeSize();
    dstrect = {m_settings->getScreenWidth() / 2 - shape_size / 2,
               m_settings->getScreenHeight() - shape_size,
               shape_size,
               shape_size};
}

void Ship::draw()
{
    SDL_RenderCopy(rR, ship_texture, NULL, &dstrect);
}

void Ship::update()
{
    if (m_movingRight && dstrect.x < m_settings->getScreenWidth() - dstrect.w)
        dstrect.x += m_settings->getShipSpeed();
    else if (m_movingLeft && dstrect.x > 0)
        dstrect.x -= m_settings->getShipSpeed();
}

void Ship::moveLeft()
{
    m_movingLeft = true;
}

void Ship::moveRight()
{
    m_movingRight = true;
}

void Ship::stopMoving()
{
    m_movingLeft = false;
    m_movingRight = false;
}