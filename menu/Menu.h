#ifndef MENU_H
#define MENU_H

#include "HighscoresPage.h"

class Menu
{
public:
    Menu(Page *page1, Page *page2);

    void run();
private:
    int status;
    Page *currentPage;

    void setTextProps();
    void updateStatus();
};

#endif
