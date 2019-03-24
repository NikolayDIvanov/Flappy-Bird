#include "Menu.h"
#include "Game.h"
#include <ctime>
#include <windows.h>

const int sW = GetSystemMetrics(SM_CXSCREEN);
const int sH = GetSystemMetrics(SM_CYSCREEN);
const float scaleFactor = sH / 1080. < sW / 1920.? sH / 1080. : sW / 1920.;
float speedFactor = 1; // The division of predefined average fps by current average fps.

int main()
{
    srand(time(NULL));
    initwindow(sW, sH, "", -3, -3);

    Game game;
    Page mainPage;
    HighscoresPage highscorePage;
    Menu game_menu(&mainPage, &highscorePage);

    while(true)
    {
        game_menu.run();
        game.run();
        highscorePage.updateHighscores(game.getPlayerScore());
    }

    return 0;
}
