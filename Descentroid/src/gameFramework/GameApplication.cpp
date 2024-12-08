//////////////////////////////////////////////////
//
//  GameApplication is the main program class for
//  Descentroids, where everything starts!
//
//////////////////////////////////////////////////

#include "framework/Core.h"
#include "gameFramework/GameApplication.h"
#include "raylib.h"
#include <iostream>
#include <string>

BrodyEngine::Application* GetApplication()
{
    return new Descentroid::GameApplication(1280, 720, "Descentroid");
}

namespace Descentroid
{
    GameApplication::GameApplication(unsigned int width, unsigned int height, std::string title)
        : Application(width, height, title),
        m_PlayerCamera{ 0 }
    {
        SetClearColor(DARKBLUE);

        m_CursorVisible = false;

        // Set up player camera
        // (I know, it should be on the player. Shut up.)
        m_PlayerCamera.projection = CAMERA_PERSPECTIVE;
        m_PlayerCamera.fovy = 60.f;
        m_PlayerCamera.target = (Vector3){ 0.f, 0.f, 1.0f };
        m_PlayerCamera.up = (Vector3){ 0.f, 1.f, 0.f };
    }

    void GameApplication::Start()
    {
        Application::Start();
        PRINTH("GameApplication", "Started!");
        // DisableCursor();
    }

    void GameApplication::Tick(float deltaTime)
    {
        Application::Tick(deltaTime);

        // Debug Commands
        // Toggle Cursor
        if (IsKeyPressed(KEY_F1) && IsKeyDown(KEY_LEFT_SHIFT))
        {
            SetCursorVisible(!m_CursorVisible);
        }
    }

    void GameApplication::Render()
    {
        Application::Render();
        BeginMode3D(m_PlayerCamera);

        DrawCube(
            (Vector3){ 0.f, 0.f, 2.f },
            1.f, 1.f, 1.f, RED
        );

        EndMode3D();
    }
}