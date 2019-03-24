#include "Bird.h"

void Bird::drawBirdBody(const int& x, const int& y, const float& scaleFactor)
{
    setfillstyle(SOLID_FILL, COLOR(230, 20, 30));
    fillellipse(x, y, 50 * scaleFactor, 42 * scaleFactor);
}

void Bird::drawBirdEyes(const int& x, const int& y, const float& scaleFactor)
{
    setfillstyle(SOLID_FILL, COLOR(245, 225, 255));
    fillellipse(x + 25 * scaleFactor, y - 16 * scaleFactor, 18 * scaleFactor, 18 * scaleFactor);

    setfillstyle(SOLID_FILL, COLOR(15, 15, 15));
    fillellipse(x + 32 * scaleFactor, y - 18 * scaleFactor, 7 * scaleFactor, 7 * scaleFactor);
}

void Bird::drawBirdBeak(const int& x, const int& y, const float& scaleFactor)
{
    int arr[] =
    {
        x + int(40 * scaleFactor), y - int(20 * scaleFactor),
        x + int(65 * scaleFactor), y + int(10 * scaleFactor),
        x + int(40 * scaleFactor), y  + int(5 * scaleFactor),
        x + int(65 * scaleFactor), y + int(10 * scaleFactor),
        x + int(40 * scaleFactor), y + int(20 * scaleFactor)
    };

    setfillstyle(SOLID_FILL, COLOR(255, 140, 0));
    fillpoly(5, arr);
}

void Bird::drawBirdHair(const int& x, const int& y, const float& scaleFactor)
{
    int arr[] =
    {
        x, y - int(42 * scaleFactor),
        x - int(10 * scaleFactor), y  - int(65 * scaleFactor),
        x, y - int(42 * scaleFactor),
        x + int(4 * scaleFactor), y - int(55 * scaleFactor),
        x, y - int(45 * scaleFactor)
    };
    fillpoly(5, arr);
}

void Bird::drawBirdWing(const int& x, const int& y, const float& scaleFactor, bool birdIsGoingUp)
{
    if(birdIsGoingUp)
    {
        setfillstyle(SOLID_FILL, COLOR(255, 0, 0));
        fillellipse(x - 25 * scaleFactor, y - 5 * scaleFactor, 35 * scaleFactor, 10 * scaleFactor);
    }
    else
    {
        setfillstyle(SOLID_FILL, COLOR(250, 20, 10));
        fillellipse(x - 25 * scaleFactor, y, 35 * scaleFactor, 20 * scaleFactor);
    }
}
