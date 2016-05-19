# Unsophisticated CMakeLists file;
# compiles source files 'as-is' (no additional build or runtime settings).

cmake_minimum_required(VERSION 3.5)

project(PlanckUnit)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES examples/test_example.c src/util/ramutil.c src/planck_unit.c)

add_executable(PlanckUnit ${SOURCE_FILES})