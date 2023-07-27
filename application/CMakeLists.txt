################################################################
# Essential Project Settings
################################################################
project(Entry
        DESCRIPTION "Entry point to this application"
        LANGUAGES CXX)

################################################################
# Add Executable and Library Linkages
################################################################
add_executable(${PROJECT_NAME} EntryPoint.cpp)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
target_link_libraries(${PROJECT_NAME} PRIVATE
        engine_library
        )