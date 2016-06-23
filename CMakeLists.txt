cmake_minimum_required(VERSION 3.5)
project(PlanckUnit)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        examples/test_example.c
        src/planck_unit.c
)

add_executable(PlanckUnit ${SOURCE_FILES})