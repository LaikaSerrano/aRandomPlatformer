cmake_minimum_required(VERSION 3.25)
project(aRandomPlatformer)

set(CMAKE_CXX_STANDARD 17)

# Set the architecture to arm64
set(CMAKE_OSX_ARCHITECTURES arm64)

# Set the path to SFML include and lib directories
set(SFML_INCLUDE_DIR "/opt/homebrew/Cellar/sfml/2.6.0/include")
set(SFML_LIB_DIR "/opt/homebrew/Cellar/sfml/2.6.0/lib")

# Include SFML headers
include_directories(${SFML_INCLUDE_DIR})

# Link SFML libraries
link_directories(${SFML_LIB_DIR})

add_subdirectory(src)

target_link_libraries(aRandomPlatformer sfml-graphics sfml-window sfml-system)
