#include "EngineCore.h"
#include <iostream>

namespace engine{

    void EngineCore::init() {
        // give window properties
        auto winProperties = WindowProperties{
            1600, 900,
            "Vulkan Engine",
            glfwGetPrimaryMonitor(),
            nullptr};

        auto isWindowInit = mWindow.initWindow(winProperties);
        if(!isWindowInit){
            std::cerr << "GLFW Window failed to initialize.\n";
            return;
        }

        // window initialized
        mIsRunning = true;
        std::cout << "Engine initialized\n";
    }

    void EngineCore::run() {
        while (mIsRunning) {
            //TODO: Engine Running Logic Here
            mWindow.run();
            mIsRunning = !mWindow.shouldClose();
        }
    }

    void EngineCore::cleanUp() {
        mWindow.cleanUp();
        std::cout << "Engine cleaned up.\n";
    }
}

