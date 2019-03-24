#include "Block.h"

int Block::width;

Block::Block(const int &prevblock_x)
{
    width = 200 * scaleFactor;
    randomizeBlockCoords(prevblock_x);

    block_u[1] = block_u[3] = 0;
    block_d[5] = block_d[7] = sH;
}

void Block::updateBlockCoords(const float &speed, const int& prevblock_x)
{
    if(blockIsOutOfScreenRange())
    {
        randomizeBlockCoords(prevblock_x);
        return;
    }

    x -= speed * scaleFactor * speedFactor;
    block_d[0] = block_d[6] = block_u[0] = block_u[6] = x;
    block_d[2] = block_d[4] = block_u[2] = block_u[4] = x + width;
}

void Block::drawBlock()
{
    fillpoly(4, block_u);
    fillpoly(4, block_d);
}

float Block::getX()
{
    return x;
}

int Block::getY()
{
    return y;
}

void Block::randomizeBlockCoords(const int& prevblock_x)
{
    x = prevblock_x + rand() % width + width * 2.5;
    y = width + rand() % (sH / 2);

    block_u[5] = block_u[7] = y;
    block_d[1] = block_d[3] = y + (240 * scaleFactor);
}

bool Block::blockIsOutOfScreenRange()
{
    return x + width <= 0;
}
