#ifndef CLOUD_H
#define CLOUD_H

#include "../include/Common.h"
#include <graphics.h>

class Cloud
{
public:
    Cloud(const int &prevcloud_x);

    float getX();
    void setEllipse(int e_x, int e_y, int e_r1, int e_r2, int ellipse_index);

    void randomizeCloudCoords(const int& prevcloud_x);
    void updateCloudCoords(const float& speed, const int& prevcloud_x);
    void drawCloud();
private:
    struct Ellipse // Every cloud is presented by 4 ellipses.
    {
        int x;
        int y;
        int r1;
        int r2;
    } m_ellipses[4];

    float x;
    int   y;

    bool cloudIsOutOfScreenRange();
};

#endif
