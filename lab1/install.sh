c#!/bin/bash

# Create the build directory if it doesn't exist
if [ ! -d "build" ]; then
  mkdir build
fi

# Navigate into the build directory
cd build

# Run CMake and Make commands
cmake ..
make

# Go back to the root directory and run CMake with Unix Makefiles
cd ..
cmake -S . -G "Unix Makefiles" -B cmake

# Create symbolic link for compile_commands.json
ln -s cmake/compile_commands.json .

# Final message
echo "Build completed and symbolic link created successfully."

