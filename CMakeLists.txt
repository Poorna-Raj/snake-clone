cmake_minimum_required(VERSION 3.10)
project(Snake)

set(raylib_DIR "F:/Software/vcpkg/vcpkg/installed/x64-windows/share/raylib")
find_package(raylib CONFIG REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)