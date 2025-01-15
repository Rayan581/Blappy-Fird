#pragma once
#include <raylib.h>

class Bird
{
private:
    Vector2 position;
    int power;
    float gravity;
    Texture2D texture;
    float size;

public:
    Bird();
    ~Bird();
    Vector2 GetPosition() const;
    float GetSize() const;
    void Update();
    void Draw();
    void Reset();
};
