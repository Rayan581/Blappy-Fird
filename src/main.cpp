#include <raylib.h>
#include "game.h"

int main()
{
    InitWindow(800, 800, "Blappy Fird");
    SetTargetFPS(60);

    Game game;
    game.InitGame(); // Initialize the game object

    // Game Loop
    while (WindowShouldClose() == false)
    {
        // 1. Event Handling

        // 2. Updating Positions
        game.Update();

        // 3. Drawing
        BeginDrawing();
        ClearBackground(SKYBLUE);
        game.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
