//
// Created by echo_ on 2023-07-27.
//
#include <iostream>
#include "../src/include/EngineCore.hpp"
int main(int argc, char **argv){
    std::cout << "This is the engine test.\n";
    EngineCore engine;
    engine.init();
    engine.run();
    engine.cleanup();
    return 0;
}