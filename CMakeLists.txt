cmake_minimum_required(VERSION 3.10)
project(Snake)

set(raylib_DIR "F:/Software/vcpkg/vcpkg/installed/x64-windows/share/raylib")
find_package(raylib CONFIG REQUIRED)

add_subdirectory(src/scene)
add_subdirectory(src/core)
add_subdirectory(src/object)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE 
    "${CMAKE_SOURCE_DIR}/include"
)

target_link_libraries(${PROJECT_NAME} PRIVATE 
    raylib
    Scene
    CoreLib
    Object
)