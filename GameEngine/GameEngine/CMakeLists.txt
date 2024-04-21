# CMakeList.txt : CMake project for GameEngine, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (GameEngine "WindowMain.cpp"  "GameEngine.h" "GameEngine.cpp")

if(WIN32)
    set_target_properties(GameEngine PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS")
endif()

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET GameEngine PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
