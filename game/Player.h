#ifndef PLAYER_H
#define PLAYER_H

#include "../include/Common.h"
#include "Bird.h"

class Player : public Bird
{
public:
    Player();

    int getScore();
    int getX();

    void draw();
    void updateCoords();
    bool hitBlock(const float& b_x, const int& b_y, const int& b_index);
    bool hitTheWindowBorder();
private:
    int score;
    int   x;
    float y;
    float m_speed;

    bool isGoingUp();
};

#endif
