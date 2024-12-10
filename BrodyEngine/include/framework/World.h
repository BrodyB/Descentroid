#pragma once

#include "framework/Core.h"
#include "framework/Object.h"
#include "raylib.h"

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
		void RenderInternal();

		virtual RayCollision GetRayCollisionWorld(Ray ray, float distance);

		template<typename ActorType>
		weak<ActorType> SpawnActor();

	protected:
		Camera3D m_MainCamera;

	private:
		virtual void BeginPlay();
		virtual void Tick(float deltaTime);
		virtual void Render2D();
		virtual void Render3D();
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