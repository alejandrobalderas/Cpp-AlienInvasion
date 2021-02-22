// Forward declarations
class AlienInvasion;
class Renderer;

#ifndef SHIP_H
#define SHIP_H

#include <string>
#include <SDL2/SDL_image.h>
#include <memory>
#include "AlienInvasion.h"
#include "Settings.h"
#include "Renderer.h"

//Forward declaration or Renderer

class Ship
{
private:
    std::string pathToImage = "../src/images/rocket.png";
    const std::shared_ptr<Settings> m_settings;
    std::shared_ptr<Renderer> m_renderer;
    SDL_Rect dstrect;
    SDL_Renderer *rR;

    int speed{100};
    int shapeSize;
    bool m_movingRight{false};
    bool m_movingLeft{false};
    SDL_Texture *shipTexture;

    void loadTexture();
    void loadDstrect();

public:
    // Ship(std::shared_ptr<Renderer>);
    Ship(AlienInvasion *game);
    void draw();
    void update();
    void moveLeft();
    void moveRight();
    void stopMovingRight();
    void stopMovingLeft();
    void getShipPositionForBullet(int &x, int &y) const;
};

#endif