#include "pipe.h"
#include <raylib.h>
#include <algorithm>

void Pipes::Pipe::Draw()
{
    // Draw the pipe
    DrawRectangle(position.x, position.y, 100, length, GREEN);
}

void Pipes::Pipe::Update()
{
    position.x -= 7;
}

void Pipes::addPipe()
{
    Vector2 position;
    int length = GetRandomValue(100, 500);
    position.x = GetScreenWidth() + 100;
    position.y = 0;
    pipes.push_back(Pipe(Vector2{position.x, position.y}, length));
    length = GetScreenHeight() - length - 200;
    position.y = GetScreenHeight() - length;
    pipes.push_back(Pipe(Vector2{position.x, position.y}, length));
}

void Pipes::removePipe()
{
    // Remove pipes that have gone off-screen
    pipes.erase(std::remove_if(pipes.begin(), pipes.end(), [](const Pipe &pipe)
                               {
        if(pipe.position.x + 100 < 0)
            return true;
        return false; }),
                pipes.end());
}

void Pipes::spawnPipe()
{
    int currentTime = GetTime();
    if (currentTime - lastSpawnTime >= 1)
    {
        addPipe();
        lastSpawnTime = currentTime;
    }
}

void Pipes::updateScore(Vector2 birdPos, int &score, bool &scoreUpdated)
{
    if (birdPos.x >= pipes.front().position.x + 50)
    {
        if (!scoreUpdated)
        {
            score++;
            scoreUpdated = true;
        }
    }
    else
        scoreUpdated = false;
}

Pipes::Pipes()
{
    addPipe();
    lastSpawnTime = GetTime();
}

void Pipes::Draw()
{
    for (auto &pipe : pipes)
        pipe.Draw();
}

void Pipes::Update(Vector2 birdPos, int &score, bool &scoreUpdated)
{
    for (auto &pipe : pipes)
        pipe.Update();

    removePipe();
    spawnPipe();

    updateScore(birdPos, score, scoreUpdated);
}

bool Pipes::checkCollision(Vector2 birdPos, float birdSize)
{
    for (auto &pipe : pipes)
    {
        if (CheckCollisionCircleRec(Vector2{float(birdPos.x + birdSize), float(birdPos.y + birdSize)}, birdSize, Rectangle{pipe.position.x, pipe.position.y, 100, (float)pipe.length}))
            // Collision detected
            return true;
    }
    return false;
}

void Pipes::Reset()
{
    pipes.clear();
    addPipe();
    lastSpawnTime = GetTime();
}
