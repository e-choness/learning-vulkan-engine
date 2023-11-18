#pragma once

#include "EngineWindow.h"
#include <volk.h>

namespace engine{
    class EngineCore {
    public:
        void Init();
        void Run();
        void CleanUp();
    private:
        EngineWindow mWindow;
        bool mIsRunning = false;
    };
}
