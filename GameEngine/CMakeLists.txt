# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("GameEngine")

include_directories(SYSTEM "${CMAKE_SOURCE_DIR}/libs/win")
# Include sub-projects.
add_subdirectory ("GameEngine")

add_subdirectory(googletest)

add_subdirectory("test")


