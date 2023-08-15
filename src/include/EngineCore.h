//
// Created by echo_ on 2023-07-27.
//
#pragma once
#include "EngineRenderer.h"
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
        EngineWindow* m_Window;
        std::unique_ptr<EngineRenderer> m_Renderer;
        bool m_IsRunning;
    };
}
