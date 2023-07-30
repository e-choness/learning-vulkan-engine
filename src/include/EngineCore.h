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
        void Init();
        void Run();
        void CleanUp();

    private:
        std::unique_ptr<EngineWindow> m_Window;
        bool m_IsRunning;
    };
}
