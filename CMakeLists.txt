cmake_minimum_required(VERSION 3.20..3.31)
project(AoC24)

set(CMAKE_CXX_STANDARD 23)

add_library(utilities
            src/utilities/utilities.hpp
            src/utilities/Pair.hpp
            src/utilities/Point.hpp
            src/utilities/utilities.cpp)

target_include_directories(utilities PUBLIC libs)
target_link_directories(utilities PUBLIC libs)

set(DAY_HEADERS
    src/days/include/day01.hpp)

set(DAY_SOURCES
    src/days/day01.cpp)

add_library(advent
            ${DAY_HEADERS}
            ${DAY_SOURCES}
            src/advent.hpp)

target_link_libraries(advent PUBLIC utilities)
target_include_directories(advent PUBLIC src/utilities)
target_link_directories(advent PUBLIC src/utilities)

add_executable(${PROJECT_NAME}
                src/args.hpp
                src/main.cpp)

target_sources(${PROJECT_NAME} PRIVATE src/inc/days.inc)

target_link_libraries(${PROJECT_NAME} PUBLIC advent)
target_include_directories(${PROJECT_NAME} PUBLIC libs src/)
target_link_directories(${PROJECT_NAME} PUBLIC libs src/)
