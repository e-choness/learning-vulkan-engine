//
// Created by echo_ on 2023-07-27.
//
#pragma once

class EngineCore {
public:
    void init();
    void run();
    void cleanup();

private:
    bool m_IsRunning;
};