cmake_minimum_required(VERSION 4.0)
project(Y2025_AdventOfCode)

set(CMAKE_CXX_STANDARD 20)

add_executable(Y2025_AdventOfCode main.cpp
        day_1/day_1.cpp
        day_1/day_1.h
        day_base.h
        day_base.cpp
        day_2/day_2.cpp
        day_2/day_2.h
        day_3/day_3.cpp
        day_3/day_3.h
        day_4/day_4.cpp
        day_4/day_4.h
)

target_include_directories (Y2025_AdventOfCode PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/day_1)