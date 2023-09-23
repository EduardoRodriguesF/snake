cmake_minimum_required(VERSION 3.27)

project(snake)

set(SOURCES "src/main.cpp" "src/game.cpp" "src/snake.cpp" "src/fruit.cpp" "src/utils.cpp")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SDL2 REQUIRED)

add_executable(snake ${SOURCES})
target_link_libraries(snake SDL2::SDL2)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)
