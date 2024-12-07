#include "framework/Application.h"
#include "raylib.h"
#include <iostream>

namespace BrodyEngine
{
    Application::Application(unsigned int width, unsigned int height, std::string title)
        : m_TargetFrameRate{ 60.f },
        m_Title{ title },
        m_Width{ width },
        m_Height{ height }
    {
        printf("///// CREATED APPLICATION\n");
    }

    void Application::Run()
    {
        InitWindow(m_Width, m_Height, m_Title.c_str());
        SetTargetFPS(m_TargetFrameRate);

        while (!WindowShouldClose())
        {
            if (!m_Started)
            {
                StartInternal();
                m_Started = true;
            }

            TickInternal(GetFrameTime());
            RenderInternal();
        }

        CloseWindow();
    }

    Application::~Application() {}

    void Application::SetClearColor(Color color)
    {
        m_ClearColor = color;
    }

    void Application::StartInternal()
    {
        Start();
    }

    void Application::TickInternal(float deltaTime)
    {
        Tick(deltaTime);
    }

    void Application::RenderInternal()
    {
        BeginDrawing();
        ClearBackground(m_ClearColor);
        Render();
        EndDrawing();
    }

    void Application::Tick(float deltaTime) {}

    void Application::Render() {}
}
