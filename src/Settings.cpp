
#include "Settings.h"
#include <iostream>

Settings::Settings()
{
    bulletSettings = std::make_unique<BulletSettings>();
}