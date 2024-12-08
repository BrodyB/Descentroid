#include "framework/World.h"
#include "framework/Core.h"
#include "framework/Actor.h"

namespace BrodyEngine
{
    World::World(Application* owningApp)
        : m_App{owningApp},
        m_BeganPlay{false},
        m_Actors{},
        m_PendingActors{}
    {

    }

    World::~World() {}

    void World::BeginPlayInternal()
    {
        if (m_BeganPlay) return;
        m_BeganPlay = true;
        BeginPlay();
    }

    void World::TickInternal(float deltaTime)
    {
        for (shared<Actor> actor : m_PendingActors)
        {
            m_Actors.push_back(actor);
            actor->BeginPlayInternal();
        }
        m_PendingActors.clear();

        for (auto iter = m_Actors.begin(); iter != m_Actors.end();)
        {
            if (iter->get()->IsPendingDestroy())
            {
                iter = m_Actors.erase(iter);
            }
            else
            {
                iter->get()->TickInternal(deltaTime);
                ++iter;
            }
        }

        Tick(deltaTime);
    }

    void World::Render()
    {
        for (auto actor : m_Actors)
        {
            actor->Render();
        }
    }

    void World::BeginPlay()
    {
        // LOG("----> BeginPlay Called");
    }

    void World::Tick(float deltaTime)
    {
        // LOG("----> Tick Called // %f", 1.f / deltaTime);
    }
}
