#include "debug/CrashTestActor.h"
#include "debug/TestWorld.h"
#include "framework/Actor.h"
#include "Vector3.h"

namespace Descentroid
{
    CrashTestActor::CrashTestActor(BrodyEngine::World *owningWorld)
        : Actor(owningWorld)
    {
        m_World = (TestWorld*)owningWorld;
    }

    void CrashTestActor::Tick(float deltaTime)
    {
        ProcessInput(deltaTime);
        CheckForCollisions();
        PerformMovement(deltaTime);
    }

    void CrashTestActor::Render2D()
    {
    }

    void CrashTestActor::Render3D()
    {
        DrawCubeWires({m_Position.x, m_Position.y, m_Position.z}, 1.f, 1.f, 1.f, GREEN);

        for (int i = 0; i < 128; i += 2)
        {
            DrawLine3D(Vector3::ToRayVector3(m_Rays[i]), Vector3::ToRayVector3(m_Rays[i + 1]), RED);
        }
    }


    void CrashTestActor::ProcessInput(float deltaTime)
    {
        //
        // Translate FORWARD / BACKWARD
        //
        if (IsKeyDown(KEY_W))
        {
            m_Velocity.x += (Forward.x * m_Acceleration) * deltaTime;
            m_Velocity.y += (Forward.y * m_Acceleration) * deltaTime;
            m_Velocity.z += (Forward.z * m_Acceleration) * deltaTime;
        }

        if (IsKeyDown(KEY_S))
        {
            m_Velocity.x += (-Forward.x * m_Acceleration) * deltaTime;
            m_Velocity.y += (-Forward.y * m_Acceleration) * deltaTime;
            m_Velocity.z += (-Forward.z * m_Acceleration) * deltaTime;
        }

        //
        // Translate UP / DOWN
        //
        if (IsKeyDown(KEY_SPACE))
        {
            m_Velocity.x += (Up.x * m_Acceleration) * deltaTime;
            m_Velocity.y += (Up.y * m_Acceleration) * deltaTime;
            m_Velocity.z += (Up.z * m_Acceleration) * deltaTime;
        }

        if (IsKeyDown(KEY_LEFT_CONTROL))
        {
            m_Velocity.x += (-Up.x * m_Acceleration) * deltaTime;
            m_Velocity.y += (-Up.y * m_Acceleration) * deltaTime;
            m_Velocity.z += (-Up.z * m_Acceleration) * deltaTime;
        }

        //
        // Translate LEFT / RIGHT
        //
        if (IsKeyDown(KEY_A))
        {
            m_Velocity.x += (Right.x * m_Acceleration) * deltaTime;
            m_Velocity.y += (Right.y * m_Acceleration) * deltaTime;
            m_Velocity.z += (Right.z * m_Acceleration) * deltaTime;
        }

        if (IsKeyDown(KEY_D))
        {
            m_Velocity.x += (-Right.x * m_Acceleration) * deltaTime;
            m_Velocity.y += (-Right.y * m_Acceleration) * deltaTime;
            m_Velocity.z += (-Right.z * m_Acceleration) * deltaTime;
        }
    }

    void CrashTestActor::CheckForCollisions()
    {
        if (m_Velocity.Length() <= 0.001f) return;

        RayCollision hit = GetCollisionSide();

        if (hit.hit)
        {
            Vector3 hitDir = Vector3(hit.point.x, hit.point.y, hit.point.z) - m_Velocity;
            if (m_Velocity.DotProduct(hitDir) > 0.f)
            {
                m_Velocity = m_Velocity.Reflect(Vector3(hit.normal.x, hit.normal.y, hit.normal.z)) * 0.6f;
            }
        }
    }

    void CrashTestActor::PerformMovement(float deltaTime)
    {
        // Translate the player
        m_Position += m_Velocity * deltaTime;
    }
    
    RayCollision CrashTestActor::GetCollisionSide()
    {
        m_ColRay.origin = m_Position;
        m_ColRay.direction = Vector3::Normalized(m_Velocity);
        m_Rays[0] = m_ColRay.origin;
        m_Rays[1] = m_Position + m_ColRay.direction;
        return m_World->GetRayCollisionWorld(m_ColRay, 1.25f);
    }
}