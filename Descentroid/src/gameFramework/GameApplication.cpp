//////////////////////////////////////////////////
//
//  GameApplication is the main program class for
//  Descentroids, where everything starts!
//
//////////////////////////////////////////////////

#include "framework/Core.h"
#include "gameFramework/GameApplication.h"
#include "TestWorld.h"
#include "raylib.h"
#include <iostream>
#include <string>

BrodyEngine::Application* GetApplication()
{
    return new Descentroid::GameApplication();
}

namespace Descentroid
{
    GameApplication::GameApplication()
        : Application(1280, 720, "Descentroid"),
        m_PlayerCamera{ 0 }
    {
        SetClearColor(DARKBLUE);

        // m_CursorVisible = false;

        // Set up player camera
        // (I know, it should be on the player. Shut up.)
        m_PlayerCamera.projection = CAMERA_PERSPECTIVE;
        m_PlayerCamera.fovy = 60.f;
        m_PlayerCamera.target = (Vector3){ 0.f, 0.f, 1.0f };
        m_PlayerCamera.up = (Vector3){ 0.f, 1.f, 0.f };

        LoadWorld<TestWorld>();
    }

    void GameApplication::Start()
    {
        PRINTH("GameApplication", "Started!");
    }

    void GameApplication::Tick(float deltaTime)
    {
        // Debug Commands
        // Toggle Cursor
        if (IsKeyPressed(KEY_F1) && IsKeyDown(KEY_LEFT_SHIFT))
        {
            SetCursorVisible(!m_CursorVisible);
        }
    }
}