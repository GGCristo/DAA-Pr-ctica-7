cmake_minimum_required(VERSION "3.9.2")

project(RAM)

set(SOURCES
  ../src/datos.cpp
  ../src/maquina.cpp
  ../src/tarea.cpp
  ../src/voraz.cpp
  )

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

SET(CMAKE_CXX_FLAGS  "-g -pedantic-errors -Wall -Wextra -std=c++17")
# set(CMAKE_CXX_FLAGS_DEBUG "-g -pedantic-errors -Wall -Wextra -std=c++17")

add_executable(my_test ${SOURCES}
               test.cpp)
add_test(NAME my_test COMMAND my_test)
