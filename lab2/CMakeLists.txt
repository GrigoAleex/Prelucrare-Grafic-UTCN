cmake_minimum_required(VERSION 3.10)
project(Laboratorul1)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(libs/glm)
add_subdirectory(libs/GLFW)

# Include GLM headers
include_directories(libs/glm)
include_directories(libs/GLFW)

# Your executable
add_executable(YourApp src/main.cpp)

# Link GLM to your executable
target_link_libraries(YourApp glm  glfw "-framework OpenGL")

