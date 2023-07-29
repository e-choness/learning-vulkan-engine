################################################################
# Set source and include directories
################################################################
set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
set(INCLUDE_DIR "${SOURCE_DIR}/include")

################################################################
# Define header and source files
################################################################
set(HEADER_LIST "${INCLUDE_DIR}/EngineCore.h"
        "${INCLUDE_DIR}/vk_engine.h"
        "${INCLUDE_DIR}/vk_init.h"
        "${INCLUDE_DIR}/vk_types.h")

set(SOURCE_LIST "${SOURCE_DIR}/EngineCore.cpp"
        "${SOURCE_DIR}/vk_engine.cpp")

################################################################
# Add library
################################################################
add_library(engine_library
        ${SOURCE_LIST}
        ${HEADER_LIST})

################################################################
# Include directories
################################################################
target_include_directories(engine_library PUBLIC ${INCLUDE_DIR})

################################################################
# link libraries
################################################################
target_link_libraries(engine_library PUBLIC
        volk
        SDL3-static
)
