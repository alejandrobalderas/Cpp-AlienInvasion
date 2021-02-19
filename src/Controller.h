#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <SDL2/SDL.h>
#include <memory>
#include "Ship.h"

class Controller
{
public:
    void handleInput(bool &quit){};
    void handleInput(SDL_Event *e, std::shared_ptr<Ship> ship, bool &quit);

private:
};

#endif