#include "bird.h"
#include <raylib.h>

Bird::Bird()
{
    position = Vector2{100, (float)GetScreenHeight() / 2};
    power = 15;
    gravity = 0;
    texture = LoadTexture("assets/images/bird.png");
    size = 40;
}

Bird::~Bird()
{
    UnloadTexture(texture);
}

Vector2 Bird::GetPosition() const
{
    return position;
}

float Bird::GetSize() const
{
    return size;
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
    DrawTexturePro(texture, Rectangle{0, 0, (float)texture.width, (float)texture.height}, Rectangle{position.x, position.y, size, size}, Vector2{0, 0}, 0.0f, WHITE);
}

void Bird::Reset()
{
    position = Vector2{100, (float)GetScreenHeight() / 2};
    power = 15;
    gravity = 0;
}
