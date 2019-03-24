#ifndef BLOCK_H
#define BLOCK_H

#include "../include/Common.h"
#include <graphics.h>

class Block
{
public:
    Block(const int &prevblock_x);

    void updateBlockCoords(const float &speed, const int& prevblock_x);
    void drawBlock();

    float getX();
    int   getY();

    void randomizeBlockCoords(const int &prevblock_x);
private:
    int block_u[8]; // Every block is presented by 2 separate blocks.
    int block_d[8]; // Each block has 4 points.
    float x;
    int   y;
    static int width;

    bool blockIsOutOfScreenRange();
};

#endif
