class AlienInvasion;
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <SDL2/SDL.h>
#include "AlienInvasion.h"

class Controller
{
public:
    void handleInput(AlienInvasion *game);
    void checkKeyDown(AlienInvasion *game);
    void checkKeyUp(AlienInvasion *game);

private:
};

#endif