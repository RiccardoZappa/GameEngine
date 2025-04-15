cmake_minimum_required(VERSION 3.21)
project(MyRenderingProject)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(assimp REQUIRED)
find_package(Bullet REQUIRED)        # Includes bullet3, linearmath
find_package(draco REQUIRED CONFIG)  # Might need custom config or FetchContent if not installed
find_package(glfw3 REQUIRED CONFIG)
find_package(glm REQUIRED CONFIG)
find_package(poly2tri REQUIRED CONFIG) # Might need custom setup
find_package(pugixml REQUIRED CONFIG)
find_package(ZLIB REQUIRED)

# Add source files
file(GLOB_RECURSE SOURCES src/*.cpp)
add_executable(MyRenderingApp ${SOURCES})

add_library(glad STATIC ${CMAKE_SOURCE_DIR}/include/glad/glad.c)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Link libraries
target_link_libraries(MyRenderingApp
    glad
    assimp::assimp
    ${BULLET_LIBRARIES}
    draco::draco
    glfw
    glm::glm
    pugixml::pugixml
    ZLIB::ZLIB
)