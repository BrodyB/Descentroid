#pragma once
#include "framework/Core.h"
#include "framework/World.h"
#include <string>
#include "raylib.h" // Just for Color

namespace BrodyEngine
{
    class World;
    class Application
    {
    public:
        Application(unsigned int width, unsigned int height, std::string title);
        void Run();
        ~Application();

        template<typename WorldType>
        weak<WorldType> LoadWorld();

    protected:
        double lifetime() const { return m_Lifetime; }
        void SetClearColor(Color color);
        void SetCursorVisible(bool visible);

        Color m_ClearColor{ BLACK };
        bool m_CursorVisible{ true };
        shared<World> m_CurrentWorld;
        shared<World> m_PendingWorld;

    private:
        void StartInternal();
        void TickInternal(float deltaTime);
        void RenderInternal();

        virtual void Start();
        virtual void Tick(float deltaTime);
        virtual void Render();

        bool m_Started{false};
        float m_TargetFrameRate;
        unsigned int m_Width{800};
        unsigned int m_Height{600};
        std::string m_Title{""};
        double m_Lifetime{0};
    };

    template<typename WorldType>
    weak<WorldType> Application::LoadWorld()
    {
        shared<WorldType> newWorld{ new WorldType{this} };
		m_PendingWorld = newWorld;
		return newWorld;
    }
}