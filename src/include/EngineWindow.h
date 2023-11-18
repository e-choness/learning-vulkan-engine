#pragma once

#define GLFW_INCLUDE_NONE

#include "EngineExtent.h"
#include <GLFW/glfw3.h>

namespace engine{
    struct WindowProperties{
        Extent2D Size = {1600, 900};
        const char* WindowTitle = {"Vulkan Engine"};
        GLFWmonitor* WindowMonitor = {nullptr};
        GLFWwindow* WindowShare = {nullptr};
    };

    class EngineWindow{
    public:
        explicit EngineWindow(WindowProperties& windowProperties);
        ~EngineWindow() = default;

        // Prevent window self copying, shared glfw window will be terminated through deconstruction
        EngineWindow(const EngineWindow &) = delete;
        EngineWindow &operator=(const EngineWindow &) = delete;

        void SetProperties(WindowProperties& windowProperties);
        bool InitWindow();
        void Run();
        void CleanUpWindow();
        bool ShouldClose();
        bool IsInitialized();
        double GetTime();
        void SetTitle(const char* title);
        GLFWwindow* GetWindowInstance() {return m_WindowInstance;}

    private:
        WindowProperties m_WinProperties;
        GLFWwindow* m_WindowInstance;
        bool m_IsInitialized;
    };
}
