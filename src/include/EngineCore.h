//
// Created by echo_ on 2023-07-27.
//
#pragma once
#include "EngineWindow.h"
#include <memory>
namespace engine{
    class EngineCore {
    public:
        EngineCore();
        ~EngineCore() = default;
        void init();
        void run();
        void cleanup();

    private:
        std::unique_ptr<EngineWindow> m_Window;
        bool m_IsRunning;
    };
}
