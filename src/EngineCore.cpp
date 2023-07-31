//
// Created by echo_ on 2023-07-27.
//

#include "EngineCore.h"
#include <iostream>

namespace engine{
    EngineCore::EngineCore() {
        auto winProperties = WindowProperties{1600, 900, "Vulkan Engine", nullptr, nullptr};
        m_Window = std::make_unique<EngineWindow>(winProperties);
    }

//    EngineCore::~EngineCore() {
//
//    }

    void EngineCore::Init() {
        m_Window->InitWindow();
        if(!m_Window->IsInitialized()){
            m_IsRunning = false;
        }
        m_IsRunning = true;
        std::cout << "Engine initialized\n";
    }

    void EngineCore::Run() {

        while (m_IsRunning) {
            //TODO: Engine Running Logic Here
            m_Window->Run();
            m_IsRunning = !m_Window->ShouldClose();
        }
    }

    void EngineCore::CleanUp() {
        if(!m_Window){
            std::cout << "No window is initiated\n";
            return;
        }
        m_Window->CleanUpWindow();
        std::cout << "Engine cleaned up.\n";
    }
}

