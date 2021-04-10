cmake_minimum_required(VERSION "3.9.2")

project(RAM)

# set(SOURCES )


# set(CMAKE_CXX_FLAGS "-O2")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_CXX_FLAGS_DEBUG "-g -pedantic-errors -Wall -Wextra -std=c++17 -fsanitize=address")
# set(CMAKE_CXX_FLAGS_DEBUG "-g -pedantic-errors -Wall -Wextra -std=c++17")

add_executable(main ${SOURCES} main.cpp)
