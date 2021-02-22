#include "Alien.h"

Alien::Alien(AlienInvasion *game) : m_game(game)
{
    rR = game->renderer->getSDLRenderer();
    shapeSize = game->settings->alien->getShapeSize();
    loadTexture();
    loadDstrect();
}
void Alien::loadTexture()
{
    SDL_Surface *img = IMG_Load(pathToImage.c_str());
    texture = SDL_CreateTextureFromSurface(rR, img);
    SDL_FreeSurface(img);
}
void Alien::loadDstrect()
{
    rRect = {m_game->settings->getScreenWidth() / 2 - shapeSize / 2,
             m_game->settings->getScreenHeight() / 2 - shapeSize,
             shapeSize,
             shapeSize};
}
void Alien::draw()
{
    SDL_RenderCopy(rR, texture, NULL, &rRect);
}

void Alien::update()
{
    // rRect.y -= m_game->settings->bullet->getBulletSpeed();
}

void Alien::setXPos(int x)
{
    rRect.x = x;
}
