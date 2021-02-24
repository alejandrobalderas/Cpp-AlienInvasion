
#include "Sprite.h"

Sprite::Sprite(AlienInvasion *game, SpriteSettings *settings) : renderer(game->renderer->getSDLRenderer())
{

    pathToImage = settings->pathToImage;
    shapeSize = settings->shapeSize;
    loadTexture();
    loadDstrect();
}

void Sprite::loadTexture()
{
    SDL_Surface *img = IMG_Load(pathToImage.c_str());
    texture = SDL_CreateTextureFromSurface(renderer, img);
    SDL_FreeSurface(img);
}

void Sprite::loadDstrect()
{
    rRect = {settings->screen->getScreenWidth() / 2,
             settings->screen->getScreenHeight() / 2,
             shapeSize,
             shapeSize};
}