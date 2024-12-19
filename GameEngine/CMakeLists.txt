cmake_minimum_required(VERSION 3.16)
project(MyRenderingProject)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
file(GLOB_RECURSE SOURCES src/*.cpp)
add_executable(MyRenderingApp ${SOURCES})

add_library(glad STATIC ${CMAKE_SOURCE_DIR}/include/glad/glad.c)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Link GLAD and other libraries to your executable
target_link_libraries(MyRenderingApp glad)

# Link libraries
target_link_libraries(MyRenderingApp 
    ${CMAKE_SOURCE_DIR}/libs/win/assimp-vc143-mt.lib
    ${CMAKE_SOURCE_DIR}/libs/win/Bullet3Common.lib
    ${CMAKE_SOURCE_DIR}/libs/win/BulletCollision.lib
    ${CMAKE_SOURCE_DIR}/libs/win/BulletDynamics.lib
    ${CMAKE_SOURCE_DIR}/libs/win/BulletInverseDynamics.lib
    ${CMAKE_SOURCE_DIR}/libs/win/BulletSoftBody.lib
    ${CMAKE_SOURCE_DIR}/libs/win/draco.lib
    ${CMAKE_SOURCE_DIR}/libs/win/glfw3.lib
    ${CMAKE_SOURCE_DIR}/libs/win/kubazip.lib
    ${CMAKE_SOURCE_DIR}/libs/win/LinearMath.lib
    ${CMAKE_SOURCE_DIR}/libs/win/minizip.lib
    ${CMAKE_SOURCE_DIR}/libs/win/poly2tri.lib
    ${CMAKE_SOURCE_DIR}/libs/win/polyclipping.lib
    ${CMAKE_SOURCE_DIR}/libs/win/pugixml.lib
    ${CMAKE_SOURCE_DIR}/libs/win/zlib.lib
)