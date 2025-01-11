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

public:
    bool gameOver;

    Game();
    void InitGame();
    void Update();
    void Draw();
};
