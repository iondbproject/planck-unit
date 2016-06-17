cmake_minimum_required(VERSION 3.5)
project(PlanckUnit)

# Use cmake -DJENKINS_BUILD=ON <project_folder> to use XML format rather than the default.
if(JENKINS_BUILD)
    add_definitions(-DPLANCK_UNIT_OUTPUT_STYLE_XML)
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        examples/test_example.c
        src/planck_unit.c
)

add_executable(PlanckUnit ${SOURCE_FILES})