cmake_minimum_required(VERSION 3.25)
project(battleship)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# //project(Google_tests)
# //add_subdirectory(lib)
# //include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

include_directories(.)
enable_testing()

SET(battleship_srcs
        src/Game.cpp
        src/Game.h
        src/Ship.cpp
        src/Ship.h
        src/Player.cpp
        src/Player.h
        src/GameBoard.cpp
        src/GameBoard.h
        src/BattleshipCliView.cpp
        src/BattleshipCliView.h)

SET(battleship_tests
        test/BoardTest.cpp
        test/GameTest.cpp)

add_executable(battleship
        src/main.cpp src/main.h
        ${battleship_srcs}
)

add_executable(battleship_test
        ${battleship_tests}
        ${battleship_srcs}
)

target_link_libraries(
        battleship_test
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(battleship_test)