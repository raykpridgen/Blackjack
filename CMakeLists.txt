cmake_minimum_required(VERSION 3.14)
project(blackjack)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)
add_subdirectory(app)
add_subdirectory(inc)
add_subdirectory(tests)

#add_executable(blackjack2 tests/blackjacktests.cpp src/Card.cpp src/Deck.cpp src/Player.cpp)
#target_link_libraries(blackjack2 PRIVATE GTest::gtest_main CardLib)


include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  DOWNLOAD_EXTRACT_TIMESTAMP ON
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

