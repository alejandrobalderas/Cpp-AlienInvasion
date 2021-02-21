#include <iostream>
#include "Bullet.h"

Bullet::Bullet(AlienInvasion *game) : m_settings(game->settings), m_renderer(game->renderer), m_ship(game->ship.get())
{
    rR = m_renderer->getSDLRenderer();
    loadTexture();
    loadDstrect();
}

void Bullet::loadTexture()
{

    SDL_Surface *img = IMG_Load(pathToImage.c_str());
    bulletTexture = SDL_CreateTextureFromSurface(rR, img);
    SDL_FreeSurface(img);
}

void Bullet::loadDstrect()
{
    int x{0};
    int y{0};

    int bulletSize = m_settings->bulletSettings->getBulletShapeSize();
    m_ship->getShipPositionForBullet(x, y);
    rRect = {x - bulletSize / 2,
             y - bulletSize,
             bulletSize,
             bulletSize};
}

void Bullet::draw()
{
    SDL_RenderCopy(rR, bulletTexture, NULL, &rRect);
}

void Bullet::update()
{
    rRect.y -= m_settings->bulletSettings->getBulletSpeed();
}
