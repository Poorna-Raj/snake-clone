set(SOURCES
    StartScene.cpp
    GameScene.cpp
)

add_library(Scene ${SOURCES})
target_include_directories(Scene PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(Scene PUBLIC raylib)
target_link_libraries(Scene PUBLIC Object)