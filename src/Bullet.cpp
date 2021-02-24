#include <iostream>
#include "Bullet.h"

Bullet::Bullet(int x, int y, AlienInvasion *game)
    : game(game),
      rR(game->renderer->getSDLRenderer()),
      Sprite(game->renderer->getSDLRenderer(), game->settings->bullet->getImagePath())
{
    setXPos(x);
    setYPos(y);
    setShapeSize(game->settings->bullet->getShapeSize());
    bulletSpeed = game->settings->bullet->getBulletSpeed();
}

void Bullet::update()
{
    rRect.y -= bulletSpeed;
}
