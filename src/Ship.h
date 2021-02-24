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
public:
    // Constructor
    Ship(AlienInvasion *game);
    // Variables

    // Methods
    void draw();
    void update();
    void moveLeft();
    void moveRight();
    void stopMovingRight();
    void stopMovingLeft();
    // Getters / Setters
    void getShipPositionForBullet(int &x, int &y) const;

private:
    // Variables
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

    // Methods

    void loadTexture();
    void loadDstrect();
};

#endif