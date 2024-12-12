#pragma once

#include "framework/Core.h"
#include "framework/Actor.h"

namespace Descentroid
{
    class TestWorld;

    class CrashTestActor : public BrodyEngine::Actor
    {
    public:
        CrashTestActor(BrodyEngine::World* owningWorld);
        virtual void Tick(float deltaTime) override;
        virtual void Render2D() override;
        virtual void Render3D() override;

    private:
        TestWorld* m_World{ nullptr };
        Vector3 m_Velocity{ 0, 0, 0 };
        float m_Acceleration{ 0.6f };
        float m_Drag{ 0.1f };
        Ray m_ColRay{};
        Vector3 m_Rays[128];

        const Vector3 Up { 0.f, 1.f, 0.f };
        const Vector3 Forward { 0.f, 0.f, 1.f };
        const Vector3 Right { 1.f, 0.f, 0.f };

        void ProcessInput(float deltaTime);
        void CheckForCollisions();
        void PerformMovement(float deltaTime);
        RayCollision GetCollisionSide();
    };
}