#include "Button.h"

Button::Button(char *t, int x, int y, BUTTON_ACTION bact)
: text(t), cx(x), cy(y), action(bact), m_pPage(NULL)
{
    calibrateBoundingBox();
}

Button::Button(char *t, int x, int y, BUTTON_ACTION bact, Page *&next)
: text(t), cx(x), cy(y), action(bact), m_pPage(next)
{
    calibrateBoundingBox();
}

void Button::draw()
{
    POINT pos;
    GetCursorPos(&pos);

    if(buttonIsHovored(pos)) setcolor(COLOR(205,92,92));
    else setcolor(COLOR(144, 238, 144));

    outtextxy(cx, cy, text);
}

bool Button::isActivated()
{
    POINT pos;
    GetCursorPos(&pos);

    return buttonIsHovored(pos) && (GetKeyState(VK_LBUTTON) & 0x100);
}

int Button::getAction()
{
    return action;
}

Page *Button::getPointedPage()
{
    return m_pPage;
}

bool Button::buttonIsHovored(POINT pos)
 {
    return pos.x >= boundingBox.ul_x && pos.y >= boundingBox.ul_y &&
              pos.x <= boundingBox.dr_x && pos.y <= boundingBox.dr_y;
}

void Button::calibrateBoundingBox()
{
    setbkcolor(0); cleardevice();
    setbkcolor(COLOR(1, 1, 1));
    outtextxy(cx, cy, text);
    // drawing text with the new bk color without changing the drawn bk color

    int x, y;
    for(x = 0; getpixel(cx + x, cy); x++);
    for(y = 0; getpixel(cx, cy + y); y++);
    boundingBox.dr_x = cx + x;
    boundingBox.dr_y = cy + y;

    for(x = 0; getpixel(cx + x, cy); x--);
    for(y = 0; getpixel(cx, cy + y); y--);
    boundingBox.ul_x = cx + x;
    boundingBox.ul_y = cy + y;
}
