#pragma once
#include "framework/Core.h"
#include "framework/Application.h"

namespace Descentroid
{
    class GameApplication : public BrodyEngine::Application
    {
    public:
        GameApplication();
        virtual void Start() override;
        virtual void Tick(float deltaTime) override;
        virtual void Render() override;
    };
}