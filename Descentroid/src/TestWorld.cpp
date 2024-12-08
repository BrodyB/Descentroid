#include "TestWorld.h"
#include "framework/World.h"
#include "framework/Core.h"

namespace Descentroid
{
    TestWorld::~TestWorld() {}
    
    void TestWorld::BeginPlay()
    {
        PRINTH("TestWorld", "Begin Play!");
    }

    void TestWorld::Tick(float deltaTime)
    {
    }
}