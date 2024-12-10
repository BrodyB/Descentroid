#include "debug/TestWorld.h"
#include "framework/Core.h"
#include "framework/World.h"
#include "PlayerShip.h"
#include "debug/Grid3DActor.h"
#include "raymath.h"
#include "config.h"

namespace Descentroid
{
    TestWorld::TestWorld(BrodyEngine::Application *owningApp)
        : World{owningApp}
    {
        m_MainCamera.projection = CAMERA_PERSPECTIVE;
        m_MainCamera.fovy = 60.f;
        m_MainCamera.target = { 0.f, 0.f, 1.f };
        m_MainCamera.up = { 0.f, 1.f, 0.f };

        // SpawnActor<Grid3DActor>();
        testTransform = MatrixTranslate(5.f, 0.f, 0.f);

        BrodyEngine::weak<PlayerShip> ship = SpawnActor<PlayerShip>();
        ship.lock()->SetCameraReference(&m_MainCamera);
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
        // std::string path = GetResourceDir() + "room_icosphere.obj";
        // environment = LoadModel(path.c_str());
        // SetMaterialTexture(&environment.materials[0], MATERIAL_MAP_DIFFUSE, wall);
        testMaterial = Material();
        // SetMaterialTexture(&testMaterial, MATERIAL_MAP_DIFFUSE, wall);
        testCube = LoadModelFromMesh(GenMeshCube(1.f, 10.f, 20.f));
    }

    void TestWorld::Tick(float deltaTime)
    {
    }

    void TestWorld::Render3D()
    {
        DrawModel(testCube, { 5.f, 0.f, 0.f }, 1.f, DARKGREEN);
        DrawSphere(lastHit.point, 0.1f, RED);
    }

    RayCollision TestWorld::GetRayCollisionWorld(Ray ray, float distance)
    {
        if (distance <= 0.f)
            return RayCollision();

        lastHit = GetRayCollisionMesh(ray, testCube.meshes[0], MatrixAdd(testCube.transform, MatrixTranslate(5.f, 0.f, 0.f)));
        PRINTH("TestWorld", "From: %f", ray.position.x);
        if (lastHit.distance > distance)
        {
            PRINT("  Too Far");
            lastHit.hit = false;
        }
        return lastHit;
    }
}