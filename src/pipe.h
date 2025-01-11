#pragma once
#include <raylib.h>
#include <vector>

class Pipes
{
private:
    class Pipe
    {
    public:
        Vector2 position;
        int length;

        Pipe(Vector2 _position, int _length) : position(_position), length(_length) {}
        void Draw();
        void Update();
    };

    std::vector<Pipe> pipes;
    float lastSpawnTime;

    void addPipe();
    void removePipe();
    void spawnPipe();
    void updateScore(Vector2 birdPos, int &score, bool &scoreUpdated);

public:
    Pipes();
    void Draw();
    void Update(Vector2 birdPos, int &score, bool &scoreUpdated);
    bool checkCollision(Vector2 birdPos);
    void Reset();
};
