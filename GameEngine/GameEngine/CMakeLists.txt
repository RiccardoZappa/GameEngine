# CMakeList.txt : CMake project for GameEngine, include source and define
# project specific logic here.
#
find_path(DIRECTX_INCLUDE_DIR d3d12.h
    PATHS ${CMAKE_CURRENT_SOURCE_DIR}/Include # Add your own paths if necessary
    PATH_SUFFIXES "include" "DirectX12"
    )

# Find DirectX libraries
find_library(DIRECTX_LIBRARIES
    NAMES d3d12.lib dxgi.lib
    PATHS ${CMAKE_CURRENT_SOURCE_DIR}/Lib # Add your own paths if necessary
    )

# Include DirectX headers
include_directories(${DIRECTX_INCLUDE_DIR})

# Add source to this project's executable.
add_executable (GameEngine "WindowMain.cpp"  "GameEngine.h" "GameEngine.cpp")

# Link against DirectX libraries
target_link_libraries(GameEngine ${DIRECTX_LIBRARIES})

if(WIN32)
    set_target_properties(GameEngine PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS")
endif()

# Define _UNICODE and UNICODE to unset character set
target_compile_definitions(GameEngine PRIVATE _UNICODE UNICODE)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET GameEngine PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
