#include "Cloud.h"

Cloud::Cloud(const int &prevcloud_x)
{
    randomizeCloudCoords(prevcloud_x);
}

float Cloud::getX()
{
    return x;
}

void Cloud::setEllipse(int e_x, int e_y, int e_r1, int e_r2, int ellipse_index)
{
    m_ellipses[ellipse_index].x  = e_x  * scaleFactor;
    m_ellipses[ellipse_index].y  = e_y  * scaleFactor;
    m_ellipses[ellipse_index].r1 = e_r1 * scaleFactor;
    m_ellipses[ellipse_index].r2 = e_r2 * scaleFactor;
}

void Cloud::randomizeCloudCoords(const int& prevcloud_x)
{
    x = prevcloud_x + rand() % int(400 * scaleFactor) + 250 * scaleFactor;
    y = rand() % int(sH / 2 + 60 * scaleFactor) + 100 * scaleFactor;
}

void Cloud::updateCloudCoords(const float& speed, const int& prevcloud_x)
{
    if(cloudIsOutOfScreenRange())
    {
        randomizeCloudCoords(prevcloud_x);
        return;
    }

    x -= speed * scaleFactor * speedFactor;
}

void Cloud::drawCloud()
{
    for(int i = 0; i < 4; i++)
        fillellipse(x + m_ellipses[i].x, y + m_ellipses[i].y, m_ellipses[i].r1, m_ellipses[i].r2);
}

bool Cloud::cloudIsOutOfScreenRange()
{
        return (x + m_ellipses[3].x + m_ellipses[3].r1) <= 0;
}
