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
    Bird(float _power) : position(Vector2{100, (float)GetScreenHeight() / 2}), power(_power), gravity(0), texture(LoadTexture("assets/images/bird1.png")) {}
    Vector2 GetPosition() const;
    void Update();
    void Draw();
};
