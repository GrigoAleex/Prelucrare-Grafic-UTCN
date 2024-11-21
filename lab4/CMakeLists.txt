cmake_minimum_required(VERSION 3.10)
project(Laboratorul1)

# C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add GLFW and GLM subdirectories
add_subdirectory(libs/glm)
add_subdirectory(libs/GLFW)

# Include GLM and GLFW headers
include_directories(libs/glm)
include_directories(libs/GLFW/include)

# Your executable
add_executable(main src/main.cpp src/Shader.cpp)

# Link libraries
target_link_libraries(main glfw "-framework OpenGL")

# macOS-specific linking (only if you're using macOS)
if(APPLE)
    target_link_libraries(main "-framework Cocoa" "-framework IOKit" "-framework CoreVideo")
endif()

# Linux-specific linking (if you're using Linux)
if(UNIX AND NOT APPLE)
    target_link_libraries(main X11 pthread)
endif()

# Copy shaders
file(COPY ${CMAKE_SOURCE_DIR}/shaders DESTINATION ${CMAKE_BINARY_DIR})

