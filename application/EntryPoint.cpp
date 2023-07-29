//
// Created by echo_ on 2023-07-27.
//

#include "vk_engine.h"
int main(int argc, char **argv){

    VulkanEngine engine;
    engine.init();
    engine.run();
    engine.cleanup();
    return 0;
}