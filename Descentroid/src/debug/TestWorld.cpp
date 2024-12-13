#include "debug/TestWorld.h"
#include "framework/Core.h"
#include "framework/World.h"
#include "debug/CrashTestActor.h"
#include "debug/Grid3DActor.h"
#include "config.h"

#include "raylib-cpp.hpp"

namespace Descentroid
{
    TestWorld::TestWorld(BrodyEngine::Application *owningApp)
        : World{owningApp}
    {
        m_MainCamera.projection = CAMERA_PERSPECTIVE;
        m_MainCamera.fovy = 60.f;
        m_MainCamera.position = { 0.f, 8.f, -8.f };
        m_MainCamera.target = { 0.f, 0.f, 1.f };
        m_MainCamera.up = { 0.f, 1.f, 0.f };

        // SpawnActor<Grid3DActor>();

        BrodyEngine::weak<CrashTestActor> ship = SpawnActor<CrashTestActor>();
        // ship.lock()->SetCameraReference(&m_MainCamera);

    }

    TestWorld::~TestWorld()
    {
        // UnloadTexture(wall);
        // UnloadModel(environment);
        // UnloadModel(testCube);
        // UnloadMaterial(testMaterial);
        // UnloadTexture(wall);
    }

    void TestWorld::BeginPlay()
    {
        PRINTH("TestWorld", "Begin Play!");
        wall = LoadTexture("assets/tex_tile.png");
        environment = LoadModel("assets/room_icosphere.obj");
        SetMaterialTexture(&environment.materials[0], MATERIAL_MAP_DIFFUSE, wall);
        // testMaterial = Material();
        // SetMaterialTexture(&testMaterial, MATERIAL_MAP_DIFFUSE, wall);
        // testCube = LoadModelFromMesh(GenMeshCube(1.f, 10.f, 20.f));
    }

    void TestWorld::Tick(float deltaTime)
    {
    }

    void TestWorld::Render3D()
    {
        // DrawModel(testCube, { -5.f, 0.f, 0.f }, 1.f, DARKGREEN);
        DrawModel(environment, {0.f, 0.f, 0.f}, 1.f, WHITE);

        if (lastHit.hit)
        {
            DrawSphere(lastHit.point, 0.1f, RED);
            DrawLine3D(lastHit.point, Vector3Add(lastHit.point, lastHit.normal), ORANGE);
        }
        else
        {
            DrawLine3D(lastHit.point, Vector3Add(lastHit.point, lastHit.normal), RED);
        }
    }

    RayCollision TestWorld::GetRayCollisionWorld(BrodyEngine::Ray ray, float distance)
    {
        if (distance <= 0.f || ray.direction == Vector3::ZERO)
            return RayCollision();

        raylib::Ray newRay = Ray::ToRayRay(ray);
        lastHit = GetRayCollisionMesh(newRay, environment.meshes[0], raylib::Matrix::Identity());

        if (lastHit.hit)
        {
            if (lastHit.distance > distance)
            {
                lastHit.hit = false;
            }
            else
            {
                PRINT("Hit!");
            }
        }
        return lastHit;
    }
}