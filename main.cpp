#include "raylib.h"
#include "core/SceneManager.h"

int main()
{
    InitWindow(500, 500, "Window");
    SetTargetFPS(60);

    SceneManager manager;

    while (!WindowShouldClose() && !manager.shouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        manager.update();
        manager.draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}