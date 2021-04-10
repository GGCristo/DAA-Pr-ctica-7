cmake_minimum_required(VERSION "3.9.2")

project(RAM)

option(ENABLE_TESTS "Enable tests" ON/OFF)
if (${ENABLE_TESTS})
  enable_testing()
  add_subdirectory(test)
else()
  add_subdirectory(src)
endif()
