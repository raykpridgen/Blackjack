add_executable(blackjack blackjack.cpp)

target_link_libraries(blackjack PRIVATE CardLib)
target_include_directories(blackjack PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
