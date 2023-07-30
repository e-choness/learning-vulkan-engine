//
// Created by echo_ on 2023-07-27.
//

#include "EngineCore.h"
#include <iostream>


namespace engine{
    EngineCore::EngineCore() {
//        init();
    }

//    EngineCore::~EngineCore() {
//
//    }

    void EngineCore::init() {
        auto winProperties = WindowProperties{1600, 900, "Vulkan Engine", nullptr, nullptr};
        m_Window = std::make_unique<EngineWindow>(winProperties);
        if(!m_Window->IsInitialized()){
            m_IsRunning = false;
        }
        m_IsRunning = true;
        std::cout << "This is initialization\n";
    }

    void EngineCore::run() {

        while (m_IsRunning) {
            std::cout << "This is the running loop\n";
            m_IsRunning = false;
        }
    }

    void EngineCore::cleanup() {
        std::cout << "This is going to clean up the garbage\n";
    }
}

