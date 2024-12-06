#include "gameFramework/GameApplication.h"
#include "raylib.h"

namespace Descentroid
{
    GameApplication::GameApplication()
        : BrodyEngine::Application(1280, 720, "Descentroid");
    {
    }

    void GameApplication::Tick(float deltaTime)
    {
    }

    void GameApplication::Render()
    {
    }
}

BrodyEngine::Application* GetApplication()
{
    return new Descentroid::GameApplication{};
}