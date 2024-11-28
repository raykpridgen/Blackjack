add_executable(
    blackjacktests
    blackjacktests.cpp
)

target_link_libraries(
  blackjacktests
  GTest::gtest_main
  CardLib
)

add_test(NAME cards COMMAND cards)