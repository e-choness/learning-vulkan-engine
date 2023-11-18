#pragma once

#define GLFW_INCLUDE_NONE

#include <GLFW/glfw3.h>

namespace engine{

    struct WindowSize{
        uint16_t Width;
        uint16_t Height;
    };

    struct WindowProperties{
        WindowSize WindowSize ;
        const char* WindowTitle;
        GLFWmonitor* WindowMonitor;
        GLFWwindow* WindowShare;
    };

    class EngineWindow{
    public:
        // Engine window basic functions
        EngineWindow()= default;
        ~EngineWindow() = default;
        bool InitWindow(WindowProperties& winProperties);
        void Run();
        void CleanUp();

        // Additional functions
        bool ShouldClose();

    private:
        void SetupGlfwCallbacks();

    private:
        WindowProperties mWinProperties;
        GLFWwindow* mGlfwWindow;
    };
}
