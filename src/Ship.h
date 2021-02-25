class AlienInvasion;
class GameSettings;

#ifndef SHIP_H
#define SHIP_H

#include <string>
#include <SDL2/SDL_image.h>
#include <memory>
#include "Sprite.h"

class Ship : public Sprite
{
public:
    // Constructor
    Ship(AlienInvasion *game);
    ~Ship();
    // Variables

    // Methods
    // void draw();
    void update() override;
    void moveLeft();
    void moveRight();
    void stopMovingRight();
    void stopMovingLeft();
    void setInitialPos();
    // Getters / Setters
    void getShipPositionForBullet(int &x, int &y) const;

private:
    // Variables
    SDL_Renderer *rR;
    bool m_movingRight{false};
    bool m_movingLeft{false};
    int screenWidth;
    int screenHeight;
    AlienInvasion *game;
    GameSettings *settings;

    // Methods
};

#endif