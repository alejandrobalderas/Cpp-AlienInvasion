#include "Alien.h"

Alien::direction Alien::currentDir = right;
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
    rRect.x += (m_game->settings->alien->getSpeed() * currentDir);
}

void Alien::setXPos(int x)
{
    rRect.x = x;
}
int Alien::getYPos()
{
    return rRect.y;
}
void Alien::setYPos(int y)
{
    rRect.y = y;
}

bool Alien::checkEdges()
{
    if (rRect.x > m_game->settings->getScreenWidth() - shapeSize || rRect.x < 0)
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
    currentDir = (currentDir == left ? right : left);
}
void Alien::returnLeftRightEdges(int &left, int &right)
{
    left = rRect.x;
    right = rRect.x + rRect.w;
}

void Alien::returnTopBottomEdges(int &top, int &bottom)
{
    top = rRect.y;
    bottom = rRect.y + rRect.h;
}
