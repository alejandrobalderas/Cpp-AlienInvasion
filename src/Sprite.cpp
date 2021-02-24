
#include "Sprite.h"
#include <iostream>
Sprite::Sprite(SDL_Renderer *renderer, std::string pathToImage)
    : renderer(renderer), pathToImage(pathToImage)
{
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
    // Default values
    rRect = {100, 100, shapeSize, shapeSize};
}

void Sprite::draw() {}
// {
// }
void Sprite::update() {}

void Sprite::setShapeSize(int size)
{
    shapeSize = size;
    rRect.w = shapeSize;
    rRect.h = shapeSize;
}
void Sprite::setXPos(int x)
{
    rRect.x = x;
}

void Sprite::setYPos(int y)
{
    rRect.y = y;
}