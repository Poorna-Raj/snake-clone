#include "raylib.h"

int main()
{
    InitWindow(500, 500, "Window");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello Snake", 240, 250, 20, PINK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}