
#include <iostream>
#include "Ship.h"

Ship::Ship(std::shared_ptr<Settings> &settings) : _settings(settings)
{

    image = IMG_Load(path_to_image.c_str());
    int shape_size = _settings->getShipShapeSize();
    dstrect = {_settings->getScreenWidth() / 2 - shape_size / 2, _settings->getScreenHeight() - shape_size, shape_size, shape_size};
}
// Ship::Ship(std::shared_ptr<Renderer> renderer) : renderer(renderer)
// {
//     image = IMG_Load(path_to_image.c_str());
//     ship_texture = SDL_CreateTextureFromSurface(renderer->getSDLRenderer(), image);
//     SDL_FreeSurface(image);
// }

void Ship::getTexture(SDL_Renderer *rR)
{
    ship_texture = SDL_CreateTextureFromSurface(rR, image);
    SDL_FreeSurface(image);
}

void Ship::draw(SDL_Renderer *renderer)
{

    SDL_RenderCopy(renderer, ship_texture, NULL, &dstrect);
}