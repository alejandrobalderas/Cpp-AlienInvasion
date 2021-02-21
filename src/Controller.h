class AlienInvasion;
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <SDL2/SDL.h>
#include <memory>
// #include "Ship.h"
#include "AlienInvasion.h"

class Controller
{
public:
    // void handleInput(SDL_Event *e, std::shared_ptr<Ship> &ship, bool &quit);
    // void checkKeyDown(SDL_Event *e, std::shared_ptr<Ship> &ship, bool &quit);
    // void checkKeyUp(SDL_Event *e, std::shared_ptr<Ship> &ship, bool &quit);

    void handleInput(AlienInvasion *game);
    void checkKeyDown(AlienInvasion *game);
    void checkKeyUp(AlienInvasion *game);

private:
};

#endif