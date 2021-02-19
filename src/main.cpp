#include <iostream>
#include "AlienInvasion.h"

// void run()
// {
//     bool continueGame = true;
//     Renderer r = Rendkerer();
//     std::cout << "after r" << std::endl;
//     size_t currentTime{0};
//     size_t lastTime = 0;
//     size_t ctr{0};

//     while (continueGame)
//     {
//         r.render();
//         currentTime = SDL_GetTicks();

//         if (currentTime > lastTime + 1000)
//         {
//             std::cout << "Hey" << std::endl;
//             lastTime = currentTime;
//             ctr += 1;

//             if (ctr >= 5)
//             {
//                 continueGame = false;
//             }
//         }
//     }
// }

int main()
{
    std::cout << "Starting Alien Invasion" << std::endl;
    AlienInvasion ai{};

    ai.runGame();
    return 0;
}