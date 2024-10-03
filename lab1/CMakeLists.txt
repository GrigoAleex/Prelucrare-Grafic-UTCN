cmake_minimum_required(VERSION 3.10)
project(Laboratorul1)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add your GLM directory
add_subdirectory(libs/glm)

# Include GLM headers
include_directories(libs/glm)
include_directories(include)

# Your executable
add_executable(YourApp src/main.cpp src/GPSLab1.cpp)

# Link GLM to your executable
target_link_libraries(YourApp glm)

