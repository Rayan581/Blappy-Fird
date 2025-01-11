#include "game.h"
#include <raylib.h>
#include <iostream>

Game::Game() {}

void Game::InitGame()
{
    score = 0;
    gameOver = false;
    scoreUpdated = true;
    bird.Reset();
    pipes.Reset();
}

void Game::Update()
{
    if (!gameOver)
    {
        bird.Update();
        pipes.Update(bird.GetPosition(), score, scoreUpdated);
        std::cout << "Score: " << score << std::endl;

        if (pipes.checkCollision(bird.GetPosition()))
            gameOver = true;
    }
}

void Game::Draw()
{
    pipes.Draw();
    bird.Draw();
}
