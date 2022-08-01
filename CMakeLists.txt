cmake_minimum_required(VERSION 3.23)
project(gameInC)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lmingw32")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/external/include)
link_directories(${PROJECT_SOURCE_DIR}/external/lib)

set(SOURCE_FILES main.cpp)
add_executable(gameInC main.cpp)

target_link_libraries(gameInC mingw32 SDL2main SDL2)