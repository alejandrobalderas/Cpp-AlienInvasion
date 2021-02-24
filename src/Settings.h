#ifndef SETTINGS_H
#define SETTINGS_H
#include <memory>
#include <string>

class BulletSettings
{
public:
    int getShapeSize() { return shapeSize; };
    int getBulletSpeed() { return bulletSpeed; }
    int getMaxBullets() { return maxBulletsAllowed; }
    std::string getImagePath() { return pathToImage; }

private:
    int bulletSpeed = 5;
    int shapeSize = 15;
    int maxBulletsAllowed = 5;
    std::string pathToImage = "./images/bullet.png";
};

class AlienSettings
{
public:
    int getShapeSize() { return shapeSize; }
    int getMaxRowNumInFleet() { return maxRowsInFleet; };
    int getSpeed() { return speed; };
    int getDropSpeed() { return dropSpeed; };
    std::string getImagePath() { return pathToImage; }

private:
    int shapeSize{70};
    int maxRowsInFleet{3};
    int speed{2};
    int dropSpeed{50};
    std::string pathToImage = "./images/ufo.png";
};
class ShipSettings
{
public:
    int getShapeSize() const { return shapeSize; }
    int getShipSpeed() const { return shipSpeed; }
    std::string getImagePath() { return path; }

private:
    int shapeSize = 60;
    int shipSpeed = 10;
    std::string path = "./images/rocket.png";
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