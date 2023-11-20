//
// Created by echo_ on 2023-07-27.
//

#include "EngineCore.h"

int main([[maybe_unused]]int argc, [[maybe_unused]]char **argv){

    auto engine = engine::EngineCore();
    engine.init();
    engine.run();
    engine.cleanUp();
    return 0;
}