cmake_minimum_required(VERSION 3.20)
project(navarro_jesus_pc2 LANGUAGES CXX)
include(CTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(pc2_lib STATIC src/segments_removal.cpp)
target_include_directories(pc2_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_executable(demo_segments demos/demo_segments.cpp)
target_link_libraries(demo_segments PRIVATE pc2_lib)

add_executable(test_segments tests/test_segments.cpp)
target_link_libraries(test_segments PRIVATE pc2_lib)

add_test(NAME test_segments COMMAND test_segments)

add_executable(bench_segments benchmark/bench_segments.cpp)
target_link_libraries(bench_segments PRIVATE pc2_lib)