cmake_minimum_required(VERSION "3.9.2")

project(RAM)

#set(SOURCES )

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(my_test ${SOURCES}
               test.cpp)
add_test(NAME my_test COMMAND my_test)
