#include <iostream>
#include "Bullet.h"

Bullet::Bullet(AlienInvasion *game) : settings(game->settings), renderer(game->renderer), m_ship(game->ship.get())
{
    rR = renderer->getSDLRenderer();
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

    int bulletSize = settings->bullet->getBulletShapeSize();
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
    rRect.y -= settings->bullet->getBulletSpeed();
}

void Bullet::returnLeftRightEdges(int &left, int &right)
{
    left = rRect.x;
    right = rRect.x + rRect.w;
}

void Bullet::returnTopBottomEdges(int &top, int &bottom)
{
    top = rRect.y;
    bottom = rRect.y + rRect.h;
}