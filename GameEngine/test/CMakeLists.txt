
# Add a test executable for your game engine tests
add_executable(GameEngineTests
    test1.cpp
    test2.cpp
    # Add more test files here as needed
)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET GameEngine PROPERTY CXX_STANDARD 20)
endif()

# Enable testing
enable_testing()

# Link Google Test to your test executable
target_link_libraries(GameEngineTests gtest gtest_main)

# Add the test executable as a test target
add_test(NAME GameEngineTests COMMAND GameEngineTests)