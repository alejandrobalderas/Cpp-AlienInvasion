
#include "Settings.h"
#include <iostream>

GameSettings::GameSettings()
{
    screen = std::make_unique<ScreenSettings>();
    bullet = std::make_unique<BulletSettings>();
    alien = std::make_unique<AlienSettings>();
    ship = std::make_unique<ShipSettings>();
}