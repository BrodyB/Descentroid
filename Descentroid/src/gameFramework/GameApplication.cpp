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
        : Application(1280, 720, "Descentroid")
    {
        SetClearColor(DARKBLUE);

        // m_CursorVisible = false;

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