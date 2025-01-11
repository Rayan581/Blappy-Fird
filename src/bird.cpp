#include "bird.h"
#include <raylib.h>
#include <iostream>

Bird::Bird()
{
    position = Vector2{100, (float)GetScreenHeight() / 2};
    power = 15;
    gravity = 0;
    texture = LoadTexture("assets/images/bird.png");
}

Bird::~Bird()
{
    UnloadTexture(texture);
    std::cout << "THis cled" << std::endl;
}

Vector2 Bird::GetPosition() const
{
    return position;
}

void Bird::Update()
{
    if (IsKeyPressed(KEY_SPACE))
        gravity = -power;

    position.y += gravity;
    gravity = gravity + 0.85 <= 15 ? gravity + 0.85 : 15;
}

void Bird::Draw()
{
    DrawTextureV(texture, position, WHITE);
}

void Bird::Reset()
{
    position = Vector2{100, (float)GetScreenHeight() / 2};
    power = 15;
    gravity = 0;
}
