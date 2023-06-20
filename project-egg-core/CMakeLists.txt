cmake_minimum_required(VERSION 3.25)
project(project-egg-core)
set(CMAKE_CXX_STANDARD 20)

set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# Dependencies from ThirdParty libraries
add_subdirectory(${PROJECT_SOURCE_DIR}/ThirdParty)
add_subdirectory(${PROJECT_SOURCE_DIR}/src)
add_subdirectory(${PROJECT_SOURCE_DIR}/Application)

#----------------------------------------------------------------
# Link third party libraries
#----------------------------------------------------------------
target_link_libraries(${PROJECT_NAME} PUBLIC
        SDL3-static
        SDL3_image
        tinyxml2)

#----------------------------------------------------------------
# Add executable files
#----------------------------------------------------------------
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/Application/EntryPoint.cpp)





