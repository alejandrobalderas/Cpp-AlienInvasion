#ifndef SETTINGS_H
#define SETTINGS_H
class Settings
{
private:
    const int SCREEN_WIDTH{1200};
    const int SCREEN_HEIGHT{800};

    int colorBackgroundR{20};
    int colorBackgroundG{20};
    int colorBackgroundB{50};
    int colorBackgroundAlpha{255};

    int target_frame_duration{1000 / 60};

    int ship_shape_size = 60;
    int ship_speed = 10;

public:
    Settings();
    int getTargetFrameDuration() const
    {
        return target_frame_duration;
    }
    int getScreenWidth() const
    {
        return SCREEN_WIDTH;
    }
    int getScreenHeight() const
    {
        return SCREEN_HEIGHT;
    }
    void getBackgroundColors(int &r, int &g, int &b, int &a) const
    {
        r = colorBackgroundR;
        g = colorBackgroundG;
        b = colorBackgroundB;
        a = colorBackgroundAlpha;
    }

    int getShipShapeSize() const { return ship_shape_size; }
    int getShipSpeed() const { return ship_speed; }
};

#endif