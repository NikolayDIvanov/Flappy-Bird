#include "Player.h"

Player::Player()
: score(0), m_speed(2)
{
    y = sH / 2;
    x = 200 * scaleFactor;
}

int Player::getScore()
{
    return score;
}

int Player::getX()
{
    return x;
}

void Player::draw()
{
    setcolor(COLOR(0, 0, 0));

    drawBirdBeak(x, y, scaleFactor);
    drawBirdBody(x, y, scaleFactor);
    drawBirdEyes(x, y, scaleFactor);
    drawBirdHair(x, y, scaleFactor);
    drawBirdWing(x, y, scaleFactor, m_speed < 0? true : false);
}

void Player::updateCoords()
{
    if(isGoingUp()) m_speed = -4.;
    else if(m_speed < 2) m_speed += 0.06 * speedFactor;

    y += m_speed * scaleFactor * speedFactor;
}

bool Player::hitBlock(const float& b_x, const int& b_y, const int& b_index)
{
    static int prev_index = -1;
    if(b_x <= 245 * scaleFactor && b_x + 200 * scaleFactor >= 155 * scaleFactor)
    {
        if(y - 25 * scaleFactor <= b_y || y + 25 * scaleFactor >= b_y + 240 * scaleFactor) return true;
        if(prev_index != b_index)
        {
            prev_index = b_index;
            score++;
        }
    }

    return false;
}

bool Player::hitTheWindowBorder()
{
    return y + 35 * scaleFactor >= sH || y - 35 * scaleFactor <= 0;
}

bool Player::isGoingUp()
{
    static bool curr_space = false, prev_space = false;

    if(GetAsyncKeyState(VK_SPACE))
        curr_space = 1;
    else
        curr_space = 0;

    if(prev_space != curr_space)
    {
        if(curr_space)
        {
            prev_space = curr_space;
            return true;
        }

        prev_space = curr_space;
    }

    return false;
}
