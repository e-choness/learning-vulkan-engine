//
// Created by echo_ on 2023-07-27.
//

#include "EngineCore.hpp"
#include <iostream>

void EngineCore::init() {
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
