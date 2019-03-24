#include "Text.h"

Text::Text(char *t, int x, int y, int color)
: cx(x), cy(y), t_color(color)
{
    strcpy(text, t);
}

void Text::changeText(char *t)
{
    strcpy(text, t);
}

void Text::draw()
{
    setcolor(t_color);
    outtextxy(cx, cy, text);
}
