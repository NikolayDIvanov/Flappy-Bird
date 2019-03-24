#include "Menu.h"

Menu::Menu(Page *page1, Page *page2)
{
    status = DO_NOTHING;
    setTextProps();

    Page *menuPage = page1;
    Page *highscoresPage = page2;

    menuPage->createText((char*)"Flappy Bird Game", sW / 2, sH / 4, COLOR(154,205,50));
    menuPage->createButton((char*)"Play Game", sW / 2, sH / 4 + 250 * scaleFactor, START);
    menuPage->createButton((char*)"Highscores", sW / 2, sH / 4 + 340 * scaleFactor, GOTO_PAGE, highscoresPage);
    menuPage->createButton((char*)"Exit Game", sW / 2, sH / 4 + 420 * scaleFactor, EXIT);
    highscoresPage->createButton((char*)"Back", sW / 2, sH - 180 * scaleFactor, GOTO_PAGE, menuPage);

    currentPage = menuPage;
}

void Menu::run()
{
    setbkcolor(COLOR(10, 10, 11));
    while(status != START)
    {
        currentPage->drawFrame();
        updateStatus();
    }
    status = DO_NOTHING;
}

void Menu::setTextProps()
{
    long int pixels = sW * sH;
    int tsize;

    if(pixels <= 800 * 600)
        tsize = 3;
    else if(pixels <= 1366 * 768)
        tsize = 4;
    else if(pixels <= 1280 * 1024)
        tsize = 5;
    else
        tsize = 6;

    settextstyle(3, HORIZ_DIR, tsize);
    settextjustify(CENTER_TEXT, CENTER_TEXT);
}

void Menu::updateStatus()
{
    status = currentPage->buttonActivated();

    if(status == GOTO_PAGE)
        currentPage = currentPage->getNextPage();
    else if(status == EXIT)
    {
        closegraph();
        exit(0);
    }
}
