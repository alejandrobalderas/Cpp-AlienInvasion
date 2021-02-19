#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <SDL2/SDL.h>

class Controller
{
public:
    void handleInput(bool &quit){};
    void handleInput(SDL_Event *e, bool &quit);

private:
};

#endif