# Add all the source files in the "src" folder to the "platformer" target
file(GLOB_RECURSE SOURCES "*.cpp")
add_executable(aRandomPlatformer ${SOURCES})

