#ifndef GAME_H
#define GAME_H

#include "../menu/Text.h"
#include "Player.h"
#include "Block.h"
#include "Cloud.h"
#include <vector>

class Game
{
public:
    Game();
    ~Game();

    void run();
    int  getPlayerScore();
private:
    int m_page;
    bool isRunning;

    Text   *scoreText;
    Player *player;
    std::vector <Block> blocks;
    std::vector <Cloud> clouds;

    void updateFrame();
    void updateStatus();
    void updateScoreText();

    void drawFrame();
    void drawBlocks();
    void drawClouds();
    void drawGameOver();

    int testRun(char str[]); // Runs a "simulation" for 1 sec and return the calculated fps.
    void countdown();
    /*
    * Counts down 3 seconds by calling testRun 3 times and calculates the "speedFactor".
    * Which is used to run the game almost identical with different display resolution settings and frame rates.
    */
    void restartGame();
};

#endif
