set(SOURCES
    Food.cpp
)

add_library(Object ${SOURCES})

target_include_directories(Object PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(Object PUBLIC raylib)