cmake_minimum_required(VERSION 3.25)
project(src)
set(CMAKE_CXX_STANDARD 20)

set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB_RECURSE PROJECT_SOURCES ${PROJECT_SOURCE_DIR}/*.h ${PROJECT_SOURCE_DIR}/*.cpp)

#add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC
        SDL3-static
        SDL3_image
        tinyxml2)


target_include_directories(${PROJECT_NAME} PUBLIC
        ${PROJECT_SOURCE_DIR}
#        ${sdl2_SOURCE_DIR}/include
#        ${sdl2image_SOURCE_DIR}/include
        ${tinyxml2_SOURCE_DIR})


add_custom_command(
TARGET ${PROJECT_NAME}
POST_BUILD
COMMAND ${CMAKE_COMMAND} -E copy_directory
${CMAKE_CURRENT_SOURCE_DIR}/../assets ${CMAKE_CURRENT_BINARY_DIR}/assets)
