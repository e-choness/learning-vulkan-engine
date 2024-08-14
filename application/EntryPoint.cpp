#include "EngineCore.h"

int main([[maybe_unused]]int argc, [[maybe_unused]]char **argv){

    auto engine = engine::EngineCore();
    engine.init();
    engine.run();
    engine.cleanUp();
    return 0;
}