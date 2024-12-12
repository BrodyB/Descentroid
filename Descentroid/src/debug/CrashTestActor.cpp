#include "debug/CrashTestActor.h"
#include "debug/TestWorld.h"
#include "framework/Actor.h"
#include "raylib.h"
#include "raymath.h"

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
        DrawCube(m_Position, 1.f, 1.f, 1.f, GREEN);

        for (int i = 0; i < 128; i += 2)
        {
            DrawLine3D(m_Rays[i], m_Rays[i + 1], GRAY);
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
        if (FloatEquals(Vector3Length(m_Velocity), 0.f)) return;

        RayCollision hit = GetCollisionSide();

        if (hit.hit)
        {
            Vector3 hitDir = Vector3Subtract(hit.point, m_Velocity);
            if (Vector3DotProduct(m_Velocity, hitDir) > 0.f)
            {
                m_Velocity = Vector3Scale(Vector3Reflect(m_Velocity, hit.normal), 0.6f);
            }
        }
    }

    void CrashTestActor::PerformMovement(float deltaTime)
    {
        // Translate the player
        m_Position.x += m_Velocity.x * deltaTime;
        m_Position.y += m_Velocity.y * deltaTime;
        m_Position.z += m_Velocity.z * deltaTime;
    }
    
    RayCollision CrashTestActor::GetCollisionSide()
    {
        RayCollision average;
        int hits = 0;

        float width = 1.f;
        float height = 1.f;
        int iterX = 0;
        int iterY = 0;

        int axisSlices = 8;

        m_ColRay.position = m_Position;
        m_ColRay.direction = Vector3Normalize(m_Velocity);
        return m_World->GetRayCollisionWorld(m_ColRay, 1.25f);


        Vector3 right = Vector3Normalize(Vector3CrossProduct(m_ColRay.direction, Up));

        for (float x = -width/2.f; x <= width/2.f; x += width/axisSlices)
        {
            for (float y = -height/2.f; y <= height/2.f; y += height/axisSlices)
            {
                m_ColRay.position = Vector3Add(m_Position, Vector3Add(Vector3Scale(right, x), Vector3Scale(Up, y)));
                RayCollision col = m_World->GetRayCollisionWorld(m_ColRay, 1.25f);

                m_Rays[(iterY)] = m_ColRay.position;
                m_Rays[(iterY)+1] = Vector3Add(m_ColRay.position, Vector3Scale(m_ColRay.direction, 1.25f));

                if (col.hit)
                {
                    m_Rays[(iterX * iterY)+1] = col.point;
                    hits += 1;
                    average.hit = average.hit || col.hit;
                    average.distance += col.distance;
                    average.normal = Vector3Add(average.normal, col.normal);
                    average.point = Vector3Add(average.point, col.point);
                }

                iterY += 2;
            }

        }

        if (average.hit)
        {
            average.distance /= hits;

            average.normal.x /= hits;
            average.normal.y /= hits;
            average.normal.z /= hits;

            average.point.x /= hits;
            average.point.y /= hits;
            average.point.z /= hits;
        }

        return average;
    }
}