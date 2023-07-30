//
// Created by echo_ on 2023-07-27.
//

#include "EngineCore.h"
int main(int argc, char **argv){

    auto engine = engine::EngineCore();
    engine.init();
    engine.run();
    engine.cleanup();
    return 0;
}