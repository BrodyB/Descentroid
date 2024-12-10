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

        virtual RayCollision GetRayCollisionWorld(Ray ray, float distance);

    private:
        virtual void BeginPlay() override;
		virtual void Tick(float deltaTime) override;
        virtual void Render3D() override;

        Texture2D wall;
        // Model environment;
        Model testCube;
        Matrix testTransform;
        Material testMaterial;
        RayCollision lastHit{};
    };
}