cmake_minimum_required(VERSION 3.25)
project(project-egg-core)
set(CMAKE_CXX_STANDARD 20)

# Dependencies from ThirdParty libraries
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/ThirdParty)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src)
