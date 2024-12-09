#pragma once

#include "framework/Core.h"
#include "framework/Object.h"

namespace BrodyEngine
{
	class Application;
	class Actor;

	class World
	{
	public:
		World(Application* owningApp);
		virtual ~World();

		void BeginPlayInternal();
		void TickInternal(float deltaTime);
		void Render();

		template<typename ActorType>
		weak<ActorType> SpawnActor();

	private:
		virtual void BeginPlay();
		virtual void Tick(float deltaTime);
		Application* m_App;
		bool m_BeganPlay;

		List<shared<Actor>> m_Actors;
		List<shared<Actor>> m_PendingActors;
	};

	template<typename ActorType>
	inline weak<ActorType> World::SpawnActor()
	{
		shared<ActorType> newActor{ new ActorType(this) };
		m_PendingActors.push_back(newActor);
		return newActor;
	}
}