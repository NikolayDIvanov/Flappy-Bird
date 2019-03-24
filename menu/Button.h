#ifndef BUTTON_H
#define BUTTON_H

#include <graphics.h>

class Page;

enum BUTTON_ACTION
{
    DO_NOTHING,
    START,
    GOTO_PAGE,
    EXIT
};

class Button
{
public:
    Button(char *t, int x, int y, BUTTON_ACTION bact);
    Button(char *t, int x, int y, BUTTON_ACTION bact, Page *&next);

    void draw();
    bool isActivated();
    int getAction();
    Page *getPointedPage();
private:
    char *text;
    int cx, cy;
    int action;

    Page *m_pPage;

    struct BoundingBox
    {
        int ul_x;
        int ul_y;
        int dr_x;
        int dr_y;
    } boundingBox;

    bool buttonIsHovored(POINT pos);
    void calibrateBoundingBox(); // Finds the "click area" of the button
};

#endif
