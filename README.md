# aRandomPlatformer

## Hello !
This project is using a lot to work. 
For now, if you want to compile it or test it (not so much is working), you need to use `cmake ./` in the main directory

Also, if you are not using a processor arm64, you will need to change the CMakeLists.txt file. You will need to delete `set(CMAKE_OSX_ARCHITECUTRES arm64)` line.

You will probably also need to change the directory where SFML is stored because the project for now is just working locally. Using the two lines after this, just change the path 

```cmake
set(SFML_INCLUDE_DIR "path/to/your/include")
set(SFML_LIB_DIR "path/to/your/lib")
```

--- 
If any information is needed, please create an issue on the repo or you can interact with me on discord using @laikaTranscat
