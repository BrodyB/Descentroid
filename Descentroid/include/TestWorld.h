#pragma once

#include "framework/World.h"
#include "framework/Application.h"

namespace Descentroid
{
    class Application;
    class TestWorld : public BrodyEngine::World
    {
    public:
        TestWorld(BrodyEngine::Application* owningApp);
        virtual ~TestWorld() override;

    private:
        virtual void BeginPlay() override;
		virtual void Tick(float deltaTime) override;
    };
}