#include "game.h"
#include <raylib.h>
#include <fstream>

int Game::getHighScore()
{
    int highScore = 0;
    std::ifstream file("assets/scores.txt");
    if (file.is_open())
    {
        std::string score;
        while (file >> score)
            highScore = std::max(highScore, std::stoi(score.c_str()));
        file.close();
    }
    return highScore;
}

void Game::DrawScore()
{
    DrawText(TextFormat("Score: %i", score), 10, 10, 30, WHITE);
    if (gameOver)
    {
        DrawText("Game Over!", GetScreenWidth() / 2 - MeasureText("Game Over!", 40) / 2, GetScreenHeight() / 2 - 40, 40, RED);
        DrawText(TextFormat("High Score: %i", getHighScore()), GetScreenWidth() / 2 - MeasureText("High Score: ", 30) / 2, GetScreenHeight() / 2 + 20, 30, YELLOW);
    }
}

void Game::SaveScore()
{
    std::fstream file("assets/scores.txt", std::ios::app);
    if (file.is_open())
    {
        file << score << std::endl;
        file.close();
    }
}

Game::Game() {}

void Game::InitGame()
{
    score = 0;
    gameOver = false;
    scoreUpdated = false;
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

        if (pipes.checkCollision(bird.GetPosition(), bird.GetSize() / 2))
            gameOver = true;
    }
    else
    {
        if (!scoreUpdated)
        {
            SaveScore();
            scoreUpdated = true;
        }
    }
}

void Game::Draw()
{
    pipes.Draw();
    bird.Draw();
    DrawScore();
}
