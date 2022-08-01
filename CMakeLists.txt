cmake_minimum_required(VERSION 3.23)
project(gameInC)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
set(CMAKE_CXX_STANDARD 11)

find_package(SDL2 REQUIRED)

include_directories(.)
include_directories(src)
include_directories(external)
include_directories(${SDL2_INCLUDE_DIR})


set(SOURCE_FILES src/main.cpp)
add_executable(gameInC src/main.cpp)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})