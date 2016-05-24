# Unsophisticated CMakeLists file;
# compiles source files 'as-is' (no additional build or runtime settings).
cmake_minimum_required(VERSION 3.5)
project(PlanckUnit)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        examples/test_example.c
        src/util/ramutil.c
        src/planck_unit.c
)

# If not using CMake, output-style variables will have to be defined elsewhere
#   in the source code or via the compiler.
# To set this variable, add "-D OUTPUT_STYLE <value>" to the command line,
#  or in CLion, in File > Settings > Build, Execution, Deployment > CMake options.
if("${OUTPUT_STYLE}" STREQUAL "json")
    add_definitions(-DPLANCK_UNIT_OUTPUT_STYLE_JSON)
    message(STATUS "Using JSON output syntax.")
elseif("${OUTPUT_STYLE}" STREQUAL "human")
    add_definitions(-DPLANCK_UNIT_OUTPUT_STYLE_HUMAN)
    message(STATUS "Using human-readable output syntax.")
elseif("${OUTPUT_STYLE}" STREQUAL "xml")
    add_definitions(-DPLANCK_UNIT_OUTPUT_STYLE_XML)
    message(STATUS "Using XML output syntax.")
else()
    add_definitions(-DPLANCK_UNIT_OUTPUT_STYLE_CONCISE)
    message(STATUS "Using concise output syntax.")
endif()

add_executable(PlanckUnit ${SOURCE_FILES})