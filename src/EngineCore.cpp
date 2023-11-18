#include "EngineCore.h"
#include <iostream>

namespace engine{

    void EngineCore::Init() {
        // give window properties
        auto winProperties = WindowProperties{
            1600, 900,
            "Vulkan Engine",
            glfwGetPrimaryMonitor(),
            nullptr};

        auto isWindowInit = mWindow.InitWindow(winProperties);
        if(!isWindowInit){
            std::cerr << "GLFW Window failed to initialize.\n";
            return;
        }

        // window initialized
        mIsRunning = true;
        std::cout << "Engine initialized\n";
    }

    void EngineCore::Run() {
        while (mIsRunning) {
            //TODO: Engine Running Logic Here
            mWindow.Run();
            mIsRunning = !mWindow.ShouldClose();
        }
    }

    void EngineCore::CleanUp() {
        mWindow.CleanUp();
        std::cout << "Engine cleaned up.\n";
    }
}

