#ifndef PAGE_H
#define PAGE_H

#include "Text.h"
#include "Button.h"
#include <vector>

class Page
{
public:
    Page();

    void createButton(char *t, int x, int y, BUTTON_ACTION bact);
    void createButton(char *t, int x, int y, BUTTON_ACTION bact, Page *&next);
    void createText(char *t, int x, int y, int color);
    void changeTextByIndex(char *t, const int& index);

    void setNextPage(Page *next);
    Page *getNextPage();

    int buttonActivated();
    void drawFrame();
protected:
    int w_page;
private:
    std::vector <Text> texts;
    std::vector <Button> buttons;

    Page *nextPage;

    void drawButtons();
    void drawTexts();
};

#endif
