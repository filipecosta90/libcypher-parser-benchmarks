cmake_minimum_required (VERSION 3.14)
set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

project (libcypher-parser-benchmarks)


# Set a default build type if none was specified
set(default_build_type "Release")

IF(NOT CMAKE_BUILD_TYPE)
    message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
    set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
            STRING "Choose the type of build." FORCE)
    # Set the possible values of build type for cmake-gui
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
            "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
ENDIF()

# disabling tests for benchmark
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Disable benchmark tests" FORCE)

add_subdirectory(deps/benchmark)

# including benchmark header files
include_directories(deps/benchmark/include)

add_executable(libcypher-parser-benchmarks libcypher_parser_benchmarks.cpp)

target_link_libraries(libcypher-parser-benchmarks cypher-parser benchmark)

if(WIN32)
    target_link_libraries(BenchmarkEverything shlwapi)
elseif(LINUX)
    target_link_libraries(BenchmarkEverything pthread)
elseif(SOLARIS)
    target_link_libraries(BenchmarkEverything kstat)
endif()