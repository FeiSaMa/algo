cmake_minimum_required(VERSION 3.20)
project(algo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 每个 tests/<题号>.cpp 一个可执行目标。
# 注意：解法文件是被 #include 进测试文件的，所以不能再作为独立源文件列进来，
# 否则会 duplicate symbol。这也是为什么这里不需要 add_library。
file(GLOB test_srcs CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/tests/[0-9]*.cpp)

foreach(t IN LISTS test_srcs)
    get_filename_component(num ${t} NAME_WE)
    add_executable(t${num} ${t})
    target_include_directories(t${num} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/leetcode)
    target_compile_options(t${num} PRIVATE -Wall -Wextra -g -O0)
endforeach()
