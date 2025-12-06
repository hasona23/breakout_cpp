#include "GameCore.hpp"
#include "raylib.h"


Zap::GameCore::GameCore(const char* title, int width, int height)
{
    InitWindow(width,height,title);
    SetTargetFPS(60);
}
Zap::GameCore::~GameCore()
{
    CloseWindow();
}
void Zap::GameCore::Run()
{
    Init();
    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();
        Update(dt);
        BeginDrawing();
        ClearBackground(RAYWHITE);
        Draw(dt);
        EndDrawing();
    }
    Close();
}