#include "bird.h"
#include <raylib.h>

Bird::Bird() {}

Bird::~Bird()
{
    UnloadTexture(texture);
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
