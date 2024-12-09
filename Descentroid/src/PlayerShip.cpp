#include "PlayerShip.h"
#include "framework/Actor.h"
#include "rcamera.h"
#include "raymath.h"

namespace Descentroid
{
    PlayerShip::PlayerShip(BrodyEngine::World *owningWorld)
        : Actor(owningWorld)
    {
    }

    void PlayerShip::BeginPlay()
    {
    }

    void PlayerShip::Tick(float deltaTime)
    {
        // Take input
        ProcessInput(deltaTime);

        if (m_Camera)
        {
            m_Camera->position.x += m_Velocity.x * deltaTime;
            m_Camera->position.y += m_Velocity.y * deltaTime;
            m_Camera->position.z += m_Velocity.z * deltaTime;

            m_Camera->target.x += m_Velocity.x * deltaTime;
            m_Camera->target.y += m_Velocity.y * deltaTime;
            m_Camera->target.z += m_Velocity.z * deltaTime;

            CameraPitch(m_Camera, m_AngularVelocity.x * deltaTime * DEG2RAD, false, false, false);
            CameraYaw(m_Camera, m_AngularVelocity.y * deltaTime * DEG2RAD, false);
            CameraRoll(m_Camera, m_AngularVelocity.z * deltaTime * DEG2RAD);
        }

        m_Velocity = Vector3MoveTowards(m_Velocity, Vector3Zero(), m_Drag * deltaTime);
        m_AngularVelocity = Vector3MoveTowards(m_AngularVelocity, Vector3Zero(), m_AngularDrag * deltaTime);
    }

    void PlayerShip::Render2D()
    {
        DrawText(
            TextFormat("Angular Vel: [%f, %f, %f]", m_AngularVelocity.x, m_AngularVelocity.y, m_AngularVelocity.z),
            8, 24, 24, RAYWHITE
        );
    }

    void PlayerShip::SetCameraReference(Camera3D *camera)
    {
        m_Camera = camera;
    }

    void PlayerShip::ProcessInput(float deltaTime)
    {
        //
        // Translate FORWARD / BACKWARD
        //
        if (IsKeyDown(KEY_W))
        {
            Vector3 fore = GetCameraForward(m_Camera);
            m_Velocity.x += (fore.x * m_Acceleration) * deltaTime;
            m_Velocity.y += (fore.y * m_Acceleration) * deltaTime;
            m_Velocity.z += (fore.z * m_Acceleration) * deltaTime;
        }

        if (IsKeyDown(KEY_S))
        {
            Vector3 back = Vector3Scale(GetCameraForward(m_Camera), -1.f);
            m_Velocity.x += (back.x * m_Acceleration) * deltaTime;
            m_Velocity.y += (back.y * m_Acceleration) * deltaTime;
            m_Velocity.z += (back.z * m_Acceleration) * deltaTime;
        }

        //
        // Translate UP / DOWN
        //
        if (IsKeyDown(KEY_SPACE))
        {
            Vector3 up = GetCameraUp(m_Camera);
            m_Velocity.x += (up.x * m_Acceleration) * deltaTime;
            m_Velocity.y += (up.y * m_Acceleration) * deltaTime;
            m_Velocity.z += (up.z * m_Acceleration) * deltaTime;
        }

        if (IsKeyDown(KEY_LEFT_CONTROL))
        {
            Vector3 up = Vector3Scale(GetCameraUp(m_Camera), -1.f);
            m_Velocity.x += (up.x * m_Acceleration) * deltaTime;
            m_Velocity.y += (up.y * m_Acceleration) * deltaTime;
            m_Velocity.z += (up.z * m_Acceleration) * deltaTime;
        }

        //
        // Translate LEFT / RIGHT
        //
        if (IsKeyDown(KEY_A))
        {
            Vector3 left = Vector3Scale(GetCameraRight(m_Camera), -1.f);
            m_Velocity.x += (left.x * m_Acceleration) * deltaTime;
            m_Velocity.y += (left.y * m_Acceleration) * deltaTime;
            m_Velocity.z += (left.z * m_Acceleration) * deltaTime;
        }

        if (IsKeyDown(KEY_D))
        {
            Vector3 right = GetCameraRight(m_Camera);
            m_Velocity.x += (right.x * m_Acceleration) * deltaTime;
            m_Velocity.y += (right.y * m_Acceleration) * deltaTime;
            m_Velocity.z += (right.z * m_Acceleration) * deltaTime;
        }


        //
        // PITCH
        //
        if (IsKeyDown(KEY_KP_8))
        {
            m_AngularVelocity.x -= m_Torque * deltaTime;
        }

        if (IsKeyDown(KEY_KP_5))
        {
            m_AngularVelocity.x += m_Torque * deltaTime;
        }

        //
        // YAW
        //
        if (IsKeyDown(KEY_KP_4))
        {
            m_AngularVelocity.y += m_Torque * deltaTime;
        }

        if (IsKeyDown(KEY_KP_6))
        {
            m_AngularVelocity.y -= m_Torque * deltaTime;
        }

        //
        // ROLL
        //
        if (IsKeyDown(KEY_Q))
        {
            m_AngularVelocity.z -= m_Torque * deltaTime;
        }

        if (IsKeyDown(KEY_E))
        {
            m_AngularVelocity.z += m_Torque * deltaTime;
        }
    }
}