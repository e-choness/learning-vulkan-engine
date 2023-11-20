#pragma once

#include "EngineWindow.h"
#include <volk.h>

namespace engine{
    class EngineCore {
    public:
        void init();
        void run();
        void cleanUp();
    private:
        EngineWindow mWindow;
        bool mIsRunning = false;
    };
}
