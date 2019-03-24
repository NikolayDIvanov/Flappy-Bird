#ifndef BIRD_H
#define BIRD_H

#include <graphics.h>

class Bird
{
protected:
    void drawBirdBody(const int& x, const int& y, const float& scaleFactor);
    void drawBirdEyes(const int& x, const int& y, const float& scaleFactor);
    void drawBirdBeak(const int& x, const int& y, const float& scaleFactor);
    void drawBirdHair(const int& x, const int& y, const float& scaleFactor);
    void drawBirdWing(const int& x, const int& y, const float& scaleFactor, bool birdIsGoingUp);
};

#endif
