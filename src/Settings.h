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

public:
    Settings();
    int getTargetFrameDuration()
    {
        return target_frame_duration;
    }
    int getScreenWidth()
    {
        return SCREEN_WIDTH;
    }
    int getScreenHeight()
    {
        return SCREEN_HEIGHT;
    }
    void getBackgroundColors(int &r, int &g, int &b, int &a)
    {
        r = colorBackgroundR;
        g = colorBackgroundG;
        b = colorBackgroundB;
        a = colorBackgroundAlpha;
    }

    int getShipShapeSize() { return ship_shape_size; }
};

#endif