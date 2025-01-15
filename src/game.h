#pragma once
#include <raylib.h>
#include "bird.h"
#include "pipe.h"

class Game
{
private:
    Bird bird;
    Pipes pipes;
    int score;
    bool scoreUpdated;
    bool gameOver;
    bool scoreSaved;

    int getHighScore();
    void DrawScore();
    void SaveScore();

public:
    Game();
    void InitGame();
    void Update();
    void Draw();
};
