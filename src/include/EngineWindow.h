#pragma once

#define GLFW_INCLUDE_NONE

#include <GLFW/glfw3.h>

namespace engine{
    struct WindowProperties{
        int Width {1600};
        int Height {900};
        const char* WindowTitle {"Vulkan Engine"};
        GLFWmonitor* WindowMonitor {glfwGetPrimaryMonitor()};
        GLFWwindow* WindowShare {nullptr};
    };

    class EngineWindow{
    public:
        // Engine window basic functions
        EngineWindow()= default;
        ~EngineWindow() = default;
        bool initWindow(WindowProperties& winProperties);
        void run();
        void cleanUp();

        // Additional functions
        bool shouldClose();

    private:
        void setupGlfwCallbacks();

    private:
        WindowProperties mWinProperties;
        GLFWwindow* mGlfwWindow;
    };
}
