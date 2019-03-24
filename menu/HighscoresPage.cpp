#include "HighscoresPage.h"

HighscoresPage::HighscoresPage()
{
    int i = 0;
    readHighscoreFile(i);
    setEmptyHighscoreText(i);

    for(i = 0; i < 10; i++)
            createText(highscores[i], sW / 2, (200 + 60 * i)  * scaleFactor, COLOR(154,205,50));
}

void HighscoresPage::updateHighscores(const int& p_score)
{
    int *scores = convertHighscoresToInt();
    if(isNewHighscore(scores, p_score))
    {
        char a[20];
        int i = 0;
        char *highscore = inputPlayerName();

        for(; i < 10; i++)
            if(p_score >= scores[i])
            {
                sprintf(a, "%d", p_score);
                strcat(highscore, a);
                break;
            }

         for(int j = 9; j > i; j--)
         {
			strcpy(highscores[j], highscores[j - 1]);
            changeTextByIndex(highscores[j], j);
         }

         strcpy(highscores[i], highscore);
         changeTextByIndex(highscores[i], i);
         writeHighscoreFile();
    }

    delete scores;
}

int* HighscoresPage::convertHighscoresToInt()
{
    int* i_scores = new int[10], i = 0;
    char a[10];

    for(; i < 10; i++)
    {
        for(int i = 0; i < 10; i++) a[i] = ' ';
        if(strcmp(highscores[i], (char*)"Empty"))
        {
            for(unsigned int j = 0; j < strlen(highscores[i]); j++)
                if(highscores[i][j] == ' ') memmove(a, highscores[i] + j, strlen(highscores[i]) - j);

            i_scores[i] = atoi(a);
        }
        else break;
    }
    while(i < 10) i_scores[i++] = 0;

    return i_scores;
}

char* HighscoresPage::inputPlayerName()
{
    char *name = new char;
    int pos = 0;
    char c;
    bool isWriten = false;

    setcolor(RED);
    setbkcolor(COLOR(10, 10, 11));
    while(!isWriten)
    {
        setactivepage(w_page);
        setvisualpage(1 - w_page);
        cleardevice();
        outtextxy(sW / 2, sH / 2 - 100 * scaleFactor, (char*)"That Is a New Record");
        outtextxy(sW / 2, sH / 2 - 30 * scaleFactor, (char*)"Type Your Name :");

        c = getch();
        switch(c)
        {
        case ' ': break;
        case 8:
            if (pos)
            {
                pos--;
                name[pos] = 0;
            }
            break;
        case 13:
            name[pos] = ' ';
            name[pos + 1] = '\0';
            isWriten = true;
            break;
        default:
            if(pos < 30 && c > ' ' && c <= '~')
            {
                name[pos] = c;
                pos++;
                name[pos] = 0;
            }
        }
        outtextxy(sW / 2 - 50 * scaleFactor, sH / 2 + 40 * scaleFactor, name);
        w_page = 1 - w_page;
    }
    return name;
}

bool HighscoresPage::isNewHighscore(int scores[], const int& p_score)
{
    if(p_score)
        for(int i = 0; i < 10; i++)
            if(p_score >= scores[i])
                return true;

    return false;
}

void HighscoresPage::readHighscoreFile(int &i)
{
    std::ifstream file;
    file.open((char*)"highscores.txt");

    if(!file.fail())
    {
        for(; !file.eof();)
            file.read((char*)&highscores[i++], 50 * sizeof(char));
        i--;
    }

    file.close();
}

void HighscoresPage::writeHighscoreFile()
{
    std::ofstream file;
    file.open((char*)"highscores.txt");
    file.write((char*)&highscores, sizeof(highscores));
    file.close();
}

void HighscoresPage::setEmptyHighscoreText(int &i)
{
    for(; i < 10; i++)
        strcpy(highscores[i], (char*)"Empty");
}
