#ifndef HIGHSCORESPAGE_H
#define HIGHSCORESPAGE_H

#include "Page.h"
#include "../Common.h"
#include <fstream>

class HighscoresPage : public Page
{
public:
    HighscoresPage();

    void updateHighscores(const int& p_score);
    int *convertHighscoresToInt();
    char *inputPlayerName();
private:
    char highscores[10][50];
    bool isNewHighscore(int scores[], const int& p_score);

    void readHighscoreFile(int& i);
    void writeHighscoreFile();

    void setEmptyHighscoreText(int& i);
};

#endif
