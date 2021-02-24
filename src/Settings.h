#ifndef SETTINGS_H
#define SETTINGS_H
#include <memory>
#include <string>

class SpriteSettings
{
public:
    std::string pathToImage;
    int shapeSize{10};
};

class BulletSettings : public SpriteSettings
{
public:
    int getBulletShapeSize() { return bulletShapeSize; };
    int getBulletSpeed() { return bulletSpeed; }
    int getMaxBullets() { return maxBulletsAllowed; }

private:
    int bulletSpeed = 5;
    int bulletShapeSize = 20;
    int maxBulletsAllowed = 5;
};

class AlienSettings : public SpriteSettings
{
public:
    int getShapeSize() { return shapeSize; }
    int getMaxRowNumInFleet() { return maxRowsInFleet; };
    int getSpeed() { return speed; };
    int getDropSpeed() { return dropSpeed; };

private:
    int shapeSize{90};
    int maxRowsInFleet{3};
    int speed{2};
    int dropSpeed{50};
};

class ScreenSettings
{
public:
    int getTargetFrameDuration() const { return target_frame_duration; }
    int getScreenWidth() const { return SCREEN_WIDTH; }
    int getScreenHeight() const { return SCREEN_HEIGHT; }
    void getBackgroundColors(int &r, int &g, int &b, int &a) const
    {
        r = colorBackgroundR;
        g = colorBackgroundG;
        b = colorBackgroundB;
        a = colorBackgroundAlpha;
    }

private:
    const int SCREEN_WIDTH{1200};
    const int SCREEN_HEIGHT{800};
    int colorBackgroundR{20};
    int colorBackgroundG{20};
    int colorBackgroundB{50};
    int colorBackgroundAlpha{255};
    int target_fps = 80;
    int target_frame_duration{1000 / target_fps};
};

class ShipSettings
{
public:
    int getShipShapeSize() const { return ship_shape_size; }
    int getShipSpeed() const { return ship_speed; }

private:
    int ship_shape_size = 60;
    int ship_speed = 10;
};

class GameSettings
{
public:
    GameSettings();
    std::unique_ptr<ScreenSettings> screen;
    std::unique_ptr<BulletSettings> bullet;
    std::unique_ptr<AlienSettings> alien;
    std::unique_ptr<ShipSettings> ship;

private:
};

#endif