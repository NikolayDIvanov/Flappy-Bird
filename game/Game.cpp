#include "Game.h"
#include <thread>
#include <chrono>

Game::Game()
: m_page(0), isRunning(true)
{
    player = new Player;
    scoreText = new Text((char*)"0", sW - 100 * scaleFactor, 100 * scaleFactor, RED);

    for(int i = 0; i < 6; i++)
        blocks.push_back(*new Block(i ? blocks[i - 1].getX() : 0));

    for(int i = 0; i < 6; i++)
        clouds.push_back(*new Cloud(i ? clouds[i - 1].getX() : 0));

    clouds[0].setEllipse(10, 0, 50, 50, 0);      clouds[1].setEllipse(0, 0, 50, 50, 0);
    clouds[0].setEllipse(40, 20, 40, 40, 1);     clouds[1].setEllipse(20, 40, 40, 40, 1);
    clouds[0].setEllipse(60, -20, 45, 40, 2);    clouds[1].setEllipse(60, 15, 70, 50, 2);
    clouds[0].setEllipse(120,15, 70, 50, 3);     clouds[1].setEllipse(100, -20, 55, 40, 3);

    clouds[2].setEllipse(60, 0, 50, 50, 0);      clouds[3].setEllipse(30, 0, 40, 50, 0);
    clouds[2].setEllipse(120, 55, 70, 50, 1);    clouds[3].setEllipse(70, 20, 60, 60, 1);
    clouds[2].setEllipse(60, 60, 45, 40, 2);     clouds[3].setEllipse(120, 10, 50, 60, 2);
    clouds[2].setEllipse(140, 20, 60, 56, 3);    clouds[3].setEllipse(140, 10, 50, 40, 3);

    clouds[4].setEllipse(10, 0, 50, 50, 0);      clouds[5].setEllipse(10, 0, 50, 50, 0);
    clouds[4].setEllipse(40, 40, 40, 40, 1);     clouds[5].setEllipse(40, 40, 40, 40, 1);
    clouds[4].setEllipse(60, -20, 55, 40, 2);    clouds[5].setEllipse(70, -20, 60, 60, 2);
    clouds[4].setEllipse(120, 15, 70, 50, 3);    clouds[5].setEllipse(120, 15, 70, 50, 3);
}

Game::~Game()
{
    delete player;
    delete scoreText;
}

void Game::run()
{
    countdown();
    restartGame();

    setbkcolor(COLOR(0, 190, 240));
    while(isRunning)
    {
        updateFrame();
        updateStatus();
        drawFrame();
    }
    delay(2000);
    drawGameOver();
}

int Game::getPlayerScore()
{
    return player->getScore();
}

void Game::updateFrame()
{
    clouds[0].updateCloudCoords(0.3, clouds[clouds.size() - 1].getX());
    for(int i = 1; i < clouds.size(); i++)
        clouds[i].updateCloudCoords(0.3, clouds[i - 1].getX());

    blocks[0].updateBlockCoords(1, blocks[blocks.size() - 1].getX());
    for(int i = 1; i < blocks.size(); i++)
        blocks[i].updateBlockCoords(1, blocks[i - 1].getX());

    player->updateCoords();
}

void Game::updateStatus()
{
    for(int i = 0; i < blocks.size(); i++)
    {
        if(player->hitBlock(blocks[i].getX(), blocks[i].getY(), i))
        {
            isRunning = false;
            return;
        }
        updateScoreText();
    }
    if(player->hitTheWindowBorder()) isRunning = false;
}

void Game::updateScoreText()
{
    char str[10];
    sprintf(str, "%d", player->getScore());
    scoreText->changeText(str);
}

void Game::drawFrame()
{
    setactivepage(m_page);
    setvisualpage(1 - m_page);
    cleardevice();

    drawClouds();
    drawBlocks();
    player->draw();
    scoreText->draw();

    m_page = 1 - m_page;
}

void Game::drawBlocks()
{
    setcolor(COLOR(10, 10, 10));
    setfillstyle(SOLID_FILL, COLOR(10, 200, 50));

    for(int i = 0; i < blocks.size(); i++)
        blocks[i].drawBlock();
}

void Game::drawClouds()
{
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);

    for(int i = 0; i < blocks.size(); i++)
        clouds[i].drawCloud();
}

void Game::drawGameOver()
{
    char a[5];
    char b[50] = "Your score is : ";
    sprintf(a, "%d", player->getScore());
    strcat(b, a);

    setactivepage(0);
    setvisualpage(0);
    setbkcolor(COLOR(10,10,11));
    cleardevice();

    outtextxy(sW / 2, sH / 2 - 100 * scaleFactor, (char*)"Game Over");
    outtextxy(sW / 2, sH / 2, b);
    delay(3000);
}

int Game::testRun(char str[])
{
    int fps = 0;
    auto start = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds;

    while(true)
    {
        fps++;
        cleardevice();

        setcolor(RED);
        outtextxy(sW / 2, sH / 2, str);

        updateFrame();
        updateStatus();
        drawFrame();

        auto end = std::chrono::system_clock::now();
        elapsed_seconds = end-start;
        if(elapsed_seconds.count() >= 1) break;
    }

    return fps;
}

void Game::countdown()
{
    int fps = 0;
    char a[2];

    for(int i = 3; i > 0; i--)
    {
        sprintf(a, "%d", i);
        fps += testRun(a);
    }
    speedFactor = 280. / (fps / 3.);
}

void Game::restartGame()
{
    delete player;
    player = new Player;
    scoreText->changeText((char*)"0");
    isRunning = true;

    for(int i = 0; i < blocks.size(); i++)
        blocks[i].randomizeBlockCoords(i ? blocks[i - 1].getX() : 0);

    for(int i = 0; i < clouds.size(); i++)
        clouds[i].randomizeCloudCoords(i ? clouds[i - 1].getX() : 0);
}
