#pragma once

#include "framework/Core.h"
#include "framework/Actor.h"
#include "Vector3.h"
#include "raylib.h"

namespace Descentroid
{
    class World;
    class TestWorld;

    class PlayerShip : public BrodyEngine::Actor
    {
    public:
        PlayerShip(BrodyEngine::World* owningWorld);
        virtual void BeginPlay() override;
        virtual void Tick(float deltaTime) override;
        virtual void Render2D() override;

        void SetCameraReference(Camera3D* camera);
        void SetMovementActive(bool active);
    
    private:
        TestWorld* m_World{ nullptr };
        Camera3D* m_Camera{ nullptr };
        BrodyEngine::Vector3 m_Velocity{ 0, 0, 0 };
        BrodyEngine::Vector3 m_AngularVelocity{ 0, 0, 0};
        float m_Acceleration{ 0.4f };
        float m_Torque{ 25.0f };
        float m_Drag{ 0.05f };
        float m_ImpactDecay{ 0.8f };
        float m_AngularDrag{ 1.f };
        bool m_MoveInputActive{ true };
        Ray m_ColRay{};

        void ProcessInput(float deltaTime);
        void CheckForCollisions();
        void PerformMovement(float deltaTime);
    };
}