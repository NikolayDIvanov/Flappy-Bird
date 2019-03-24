#ifndef TEXT_H
#define TEXT_H

#include <graphics.h>

class Text
{
public:
    Text(char *t, int x, int y, int color);

    void changeText(char *t);
    void draw();
private:
    int cx, cy;
    int t_color;
    char text[256];
};

#endif
