#include "gameFramework/GameApplication.h"
#include "raylib.h"
#include <iostream>
#include <string>

BrodyEngine::Application* GetApplication()
{
    return new Descentroid::GameApplication{};
}

namespace Descentroid
{
    GameApplication::GameApplication()
        : BrodyEngine::Application(1280, 720, "Descentroid")
    {
    }

    void GameApplication::Start()
    {
        
    }

    void GameApplication::Tick(float deltaTime)
    {
        // printf("/// GAME APPLICATION TICK");
    }

    void GameApplication::Render()
    {
    }
}