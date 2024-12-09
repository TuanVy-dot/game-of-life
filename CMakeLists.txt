cmake_minimum_required(VERSION 3.10)

project(Life C)

set(SOURCES
    src/main.c
    src/life/life_alg.c
    src/life/life_gen.c
    src/life/life_utils.c
)

include_directories(include)

add_executable(
    life ${SOURCES}
)
target_link_libraries(life SDL2)
