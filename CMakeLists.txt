cmake_minimum_required(VERSION 3.0)
project(gameInC)


set(CMAKE_CXX_STANDARD 11)

#find REQ libs
find_package(SDL2 CONFIG REQUIRED)
find_package(sdl2-image CONFIG REQUIRED)
#~~~~~~~

include_directories(.)
include_directories(src)
include_directories(external)
include_directories(assets)


set(SOURCE_FILES src/main.cpp)
add_executable(${PROJECT_NAME} src/main.cpp src/Core/Game.cpp src/Core/Game.h)

#link libs
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 SDL2::SDL2main)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2_image)