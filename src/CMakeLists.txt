################################################################
# Set source and include directories
################################################################
set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
set(INCLUDE_DIR "${SOURCE_DIR}/include")

################################################################
# Define header files
################################################################
set(HEADER_LIST ${INCLUDE_DIR}/EngineCore.hpp
        ${INCLUDE_DIR}/vk_engine.hpp
        ${INCLUDE_DIR}/vk_init.h
        ${INCLUDE_DIR}/vk_types.hpp)

################################################################
# Add library
################################################################
add_library(engine_library "${SOURCE_DIR}/EngineCore.cpp" ${HEADER_LIST})

################################################################
# Include directories
################################################################
target_include_directories(engine_library PRIVATE ${INCLUDE_DIR})