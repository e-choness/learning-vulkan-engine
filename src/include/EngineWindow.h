//
// Created by echo_ on 2023-07-29.
//
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

        void SetProperties(WindowProperties& windowProperties);
        bool InitWindow();
        void Run();
        void CleanUpWindow();
        bool ShouldClose();
        bool IsInitialized();
        double GetTime();
        void SetTitle(const char* title);
    private:
        WindowProperties m_WinProperties;
        GLFWwindow* m_WindowInstance;
        bool m_IsInitialized;
    };
}
