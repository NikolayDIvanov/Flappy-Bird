#include "Page.h"

Page::Page()
: w_page(0), nextPage(NULL) {}

void Page::createButton(char *t, int x, int y, BUTTON_ACTION bact)
{
    Button o(t, x, y, bact);
    buttons.push_back(o);
}

void Page::createButton(char *t, int x, int y, BUTTON_ACTION bact, Page *&next)
{
    Button o(t, x, y, bact, next);
    buttons.push_back(o);
}

void Page::createText(char *t, int x, int y, int color)
{
    Text o(t, x, y, color);
    texts.push_back(o);
}

void Page::changeTextByIndex(char *t, const int& index)
{
    texts[index].changeText(t);
}

void Page::setNextPage(Page *next)
{
    nextPage = next;
}

Page *Page::getNextPage()
{
    return nextPage;
}

int Page::buttonActivated()
{
    int status = DO_NOTHING;

    for(unsigned int i = 0; i < buttons.size(); i++)
        if(buttons[i].isActivated())
        {
            status = buttons[i].getAction();
            if(status == GOTO_PAGE) nextPage = buttons[i].getPointedPage();
            break;
        }

    return status;
}

void Page::drawFrame()
{
    setactivepage(w_page);
    setvisualpage(1 - w_page);
    cleardevice();

    drawTexts();
    drawButtons();

    w_page = 1 - w_page;
}

void Page::drawButtons()
{
    for(unsigned int i = 0; i < buttons.size(); i++)
        buttons[i].draw();
}

void Page::drawTexts()
{
    for(unsigned int i = 0; i < texts.size(); i++)
        texts[i].draw();
}
