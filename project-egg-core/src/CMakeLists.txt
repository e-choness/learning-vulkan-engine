#----------------------------------------------------------------
# Copyright (c) 2013 Echo Yin
#----------------------------------------------------------------
#----------------------------------------------------------------
# Project settings
#----------------------------------------------------------------
cmake_minimum_required(VERSION 3.25)
project(src)
set(CMAKE_CXX_STANDARD 20)

#----------------------------------------------------------------
# Set source directory
#----------------------------------------------------------------
set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

#----------------------------------------------------------------
# Query headers and source files
#----------------------------------------------------------------
file(GLOB_RECURSE PROJECT_SOURCES ${PROJECT_SOURCE_DIR}/*.h ${PROJECT_SOURCE_DIR}/*.cpp)

#----------------------------------------------------------------
# Add executable files
#----------------------------------------------------------------
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} main.cpp Object/ObjectProperties.h Graphics/RenderProperties.h Graphics/AssetProperties.h)

#----------------------------------------------------------------
# Link third party libraries
#----------------------------------------------------------------
target_link_libraries(${PROJECT_NAME} PUBLIC
        SDL3-static
        SDL3_image
        tinyxml2)

#----------------------------------------------------------------
# Include third-party headers
#----------------------------------------------------------------
target_include_directories(${PROJECT_NAME} PUBLIC
        ${PROJECT_SOURCE_DIR}
#        ${sdl2_SOURCE_DIR}/include
#        ${sdl2_image_SOURCE_DIR}/include
        ${tinyxml2_SOURCE_DIR})

#----------------------------------------------------------------
# Include third party headers
#----------------------------------------------------------------
#add_custom_command(
#TARGET ${PROJECT_NAME}
#POST_BUILD
#COMMAND ${CMAKE_COMMAND} -E copy_directory
#${CMAKE_CURRENT_SOURCE_DIR}/../assets ${CMAKE_CURRENT_BINARY_DIR}/assets)
