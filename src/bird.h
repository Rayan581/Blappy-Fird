#pragma once
#include <raylib.h>

class Bird
{
private:
    Vector2 position;
    int power;
    float gravity;
    Texture2D texture;

public:
    Bird();
    ~Bird();
    Vector2 GetPosition() const;
    void Update();
    void Draw();
    void Reset();
};
