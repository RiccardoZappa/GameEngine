# CMakeList.txt : CMake project for GameEngine, include source and define
# project specific logic here.
#
  cmake_minimum_required(VERSION 3.27)


# Add source to this project's executable.
add_executable (GameEngine "Main.cpp"
                            "../include/glad/glad.c"
                            "Utils/mesh.h"
                            "Utils/model.h"
                            "Utils/shaders.h")


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET GameEngine PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

# Include directories
target_include_directories(GameEngine PRIVATE 
    ${CMAKE_SOURCE_DIR}/include
)

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
target_link_libraries(GameEngine PRIVATE ${LINK_LIBRARIES})

# Define shader directory
set(SHADER_DIR ${CMAKE_SOURCE_DIR}/GameEngine/shaders)

# Add shaders to the executable target as sources (optional, just for IDEs)
target_sources(GameEngine PRIVATE
    ${SHADER_DIR}/00_basic.vert
    ${SHADER_DIR}/00_basic.frag
)

# Install shaders to the binary directory
install(FILES ${SHADER_DIR}/00_basic.vert ${SHADER_DIR}/00_basic.frag DESTINATION shaders)
