################################################################
# Set source and include directories
################################################################
set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
set(INCLUDE_DIR "${SOURCE_DIR}/include")

################################################################
# Define header and source files
################################################################
file(GLOB HEADER_LIST ${INCLUDE_DIR}/*.h
        ${INCLUDE_DIR}/*.hpp)
file(GLOB SOURCE_LIST ${SOURCE_DIR}/*.cpp)

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
        glfw
        volk
        SDL3-static
        vk-bootstrap::vk-bootstrap
)
