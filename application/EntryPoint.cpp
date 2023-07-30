//
// Created by echo_ on 2023-07-27.
//

#include "EngineCore.h"
#include <stdexcept>
int main(int argc, char **argv){

    auto engine = engine::EngineCore();
    engine.Init();
    engine.Run();
    engine.CleanUp();
    return 0;
}