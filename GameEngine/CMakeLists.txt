# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("GameEngine")

# Include sub-projects.
add_subdirectory ("GameEngine")

add_subdirectory(googletest)

# Enable testing
enable_testing()

# Add a test executable for your game engine tests
add_executable(GameEngineTests
    test/test1.cpp
    test/test2.cpp
    # Add more test files here as needed
)

# Link Google Test to your test executable
target_link_libraries(GameEngineTests gtest gtest_main)

# Add the test executable as a test target
add_test(NAME GameEngineTests COMMAND GameEngineTests)