#include "framework/Application.h"
#include "raylib.h"
#include <iostream>

namespace BrodyEngine
{
    Application::Application(unsigned int width, unsigned int height, std::string title)
        : m_TargetFrameRate{ 60.f },
        m_Title{ title },
        m_Width{ width },
        m_Height{ height },
        m_CurrentWorld{ nullptr },
        m_Lifetime{ 0 }
    {
        printf("///// CREATED APPLICATION\n");
    }

    void Application::Run()
    {
        InitWindow(m_Width, m_Height, m_Title.c_str());
        SetTargetFPS(m_TargetFrameRate);
        if (!m_CursorVisible) DisableCursor();

        while (!WindowShouldClose())
        {
            m_Lifetime += GetFrameTime();

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

    void Application::SetCursorVisible(bool visible)
    {
        if (visible)
        {
            EnableCursor();
        }
        else
        {
            DisableCursor();
        }

        m_CursorVisible = visible;
    }

    void Application::StartInternal()
    {
        Start();
    }

    void Application::TickInternal(float deltaTime)
    {
        Tick(deltaTime);

        if (m_CurrentWorld)
        {
            m_CurrentWorld->TickInternal(deltaTime);
        }

        if (m_PendingWorld && m_PendingWorld != m_CurrentWorld)
        {
            m_CurrentWorld = m_PendingWorld;
            m_CurrentWorld->BeginPlayInternal();
        }
    }

    void Application::RenderInternal()
    {
        BeginDrawing();
        ClearBackground(m_ClearColor);
        Render();
        EndDrawing();
    }

    void Application::Start() {}

    void Application::Tick(float deltaTime) {}

    void Application::Render()
    {
        if (m_CurrentWorld)
        {
            m_CurrentWorld->Render();
        }
    }
}
