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

        SpawnActor<Grid3DActor>();

        BrodyEngine::weak<PlayerShip> ship = SpawnActor<PlayerShip>();
        ship.lock()->SetCameraReference(&m_MainCamera);
    }

    TestWorld::~TestWorld()
    {
        // UnloadModel(environment);
    }
    
    void TestWorld::BeginPlay()
    {
        PRINTH("TestWorld", "Begin Play!");
        Texture tex = LoadTexture("assets/tex_tile.png");
        std::string path = GetResourceDir() + "room_icosphere.obj";
        environment = LoadModel(path.c_str());
        SetMaterialTexture(&environment.materials[0], MATERIAL_MAP_DIFFUSE, tex);
    }

    void TestWorld::Tick(float deltaTime)
    {
    }

    void TestWorld::Render3D()
    {
        DrawModel(environment, (Vector3){0.f, 0.f, 0.f}, 1.f, WHITE);
    }
}