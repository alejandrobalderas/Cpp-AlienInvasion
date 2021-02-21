
#include "Settings.h"
#include <iostream>

Settings::Settings()
{
    bullet = std::make_unique<BulletSettings>();
    alien = std::make_unique<AlienSettings>();
}