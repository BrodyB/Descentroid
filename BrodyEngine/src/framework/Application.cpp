#include "framework/Application.h"
#include "raylib.h"

namespace BrodyEngine
{
    Application::Application(unsigned int width, unsigned int height, const char* title)
        : m_TargetFrameRate{ 60.f }
    {
        InitWindow(width, height, title);
        SetTargetFPS(m_TargetFrameRate);

        while (!WindowShouldClose())
        {
            TickInternal(GetFrameTime());
            RenderInternal();
        }

        CloseWindow();
    }

    void Application::TickInternal(float deltaTime)
    {
        Tick(deltaTime);
    }

    void Application::RenderInternal()
    {
        BeginDrawing();
        ClearBackground(DARKGRAY);
        Render();
        EndDrawing();
    }

    void Application::Tick(float deltaTime) {}

    void Application::Render() {}
}