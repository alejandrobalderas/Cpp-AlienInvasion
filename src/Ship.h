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
    void draw() override;
    void update() override;
    void moveLeft();
    void moveRight();
    void stopMovingRight();
    void stopMovingLeft();
    // Getters / Setters
    void getShipPositionForBullet(int &x, int &y) const;

private:
    // Variables
    SDL_Renderer *rR;
    int speed{100};
    int shapeSize;
    bool m_movingRight{false};
    bool m_movingLeft{false};
    AlienInvasion *game;
    GameSettings *settings;
    int screenWidth;
    int screenHeight;

    // Methods
    void loadTexture();
    void loadDstrect();
    void setInitialPos();
};

#endif