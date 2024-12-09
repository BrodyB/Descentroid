#include "TestWorld.h"
#include "framework/World.h"
#include "framework/Core.h"
#include "Grid3DActor.h"

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
    }

    TestWorld::~TestWorld() {}
    
    void TestWorld::BeginPlay()
    {
        PRINTH("TestWorld", "Begin Play!");
    }

    void TestWorld::Tick(float deltaTime)
    {
    }
}