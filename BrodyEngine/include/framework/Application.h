#pragma once
#include "framework/Core.h"
#include "framework/World.h"
#include <string>
#include "raylib.h"

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
        virtual void Start() = 0;
        virtual void Tick(float deltaTime) = 0;
        virtual void Render() = 0;

        double lifetime() const { return m_Lifetime; }
        void SetClearColor(Color color);
        void SetCursorVisible(bool visible);

        Color m_ClearColor{ BLACK };
        bool m_CursorVisible{ true };
        shared<World> m_CurrentWorld;

    private:
        void StartInternal();
        void TickInternal(float deltaTime);
        void RenderInternal();

        bool m_Started{false};
        float m_TargetFrameRate;
        unsigned int m_Width{800};
        unsigned int m_Height{600};
        std::string m_Title;
        double m_Lifetime;
    };

    template<typename WorldType>
    weak<WorldType> Application::LoadWorld()
    {
        shared<WorldType> newWorld{ new WorldType{this} };
        m_CurrentWorld = newWorld;
        return newWorld;
    }
}