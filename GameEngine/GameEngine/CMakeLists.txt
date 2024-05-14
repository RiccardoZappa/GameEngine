# CMakeList.txt : CMake project for GameEngine, include source and define
# project specific logic here.
#
  cmake_minimum_required(VERSION 3.27)


# Add source to this project's executable.
add_executable (GameEngine "Main.cpp"   
                            "../include/glad/glad.c")


# Define _UNICODE and UNICODE to unset character set
target_compile_definitions(GameEngine PRIVATE _UNICODE UNICODE)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET GameEngine PROPERTY CXX_STANDARD 20)
endif()

add_subdirectory("Utils")
# TODO: Add tests and install targets if needed.

# Set include directories
include_directories(../include)
# Set linker flags
set(LINK_LIBRARIES  
    ../../../libs/win/assimp-vc143-mt
    ../../../libs/win/zlib
    ../../../libs/win/minizip
    ../../../libs/win/kubazip
    ../../../libs/win/poly2tri
    ../../../libs/win/polyclipping
    ../../../libs/win/glfw3
    ../../../libs/win/draco
    ../../../libs/win/pugixml
    gdi32
    user32
    Shell32
    Advapi32)

# Link against Utils libraries
target_link_libraries(GameEngine ${LINK_LIBRARIES})