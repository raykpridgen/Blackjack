# Details for BlackJack Application

## Tools to use for BlackJack
    - cmake		(compile and link all source code)
    - gtest		(unit test all public class functions)
	- doxygen 	(documentation)

## Directory Structure

Create the following folder structure in the root directory [probably called CPPBlackJack]

-   app - This folder will hold the main, probably called game.cpp or blackjack.cpp, CMakeLists.txt
-   build - cmake build files (you should never alter any of the files in the build folder)
-   docs - doxygen files (doxygen -g)
-   inc - Card.h, Deck.h, Player.h, CMakeLists.txt (these might also be .hpp files)
-   src - Card.cpp, Deck.cpp, Player.cpp, CMakeLists.txt
-   tests - unit tests, CMakeLists.txt
-   CMakeLists.txt
-   README.md

Best practices say that each and every folder (except for build and docs) has it's own CMakeLists.txt file.
Each CMakeLists.txt has its purpose.


## app folder
add_executable(blackjack game.cpp)

target_link_libraries(blackjack PRIVATE CardLib)
target_include_directories(blackjack PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

## src folder
add_library(CardLib STATIC 
    Card.cpp 
    Deck.cpp 
    Player.cpp)

target_include_directories(CardLib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

## inc folder
target_include_directories(CardLib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")


## All gtest unit testing below can wait

-	But in a production environment you could design unit tests first.

## tests folder
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

## root CMakeLists.txt
cmake_minimum_required(VERSION 3.14)
project(blackjack)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)
add_subdirectory(app)
add_subdirectory(inc)

#add_executable(blackjack2 ../tests/blackjacktests.cpp ../src/Card.cpp ../src/Deck.cpp ../src/Player.cpp)

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

add_subdirectory(tests)






Card concepts:

Club
Spade
Diamond
Heart

 _____________
| ACE         |
| CLUB        |
|             |
|             |
|             |
|        CLUB |
|         ACE |
|_____________|

 _____________
| ACE         |
| CLUB        |
|             |
|             |
|             |
|        CLUB |
|         ACE |
|_____________|

 _________________
| A | 10          |
| C | DIAMONDS    |
|   |             |
|   |             |
|   |             |
|   |    DIAMONDS |
|   |          10 |
|___|_____________|

 _____________________
| A | 10| 3           |
| C | D | HEARTS      |
|   |   |             |
|   |   |             |
|   |   |             |
|   |   |      HEARTS |
|   |   |           3 |
|___|___|_____________|


/////////////////////////////////////////////////////

     ______    __   __    _______    ________   __
    |  __  \  |  | |  |  |       |  |___  ___| |  |
    |_   __/  |  | |  |  |    ___|     |  |    |  |
    |  __  \  |  | |  |   \___  \      |  |    |__| 
    |      |  |  |_|  |  |       |     |  |     __ 
    |______/  |_______|  |_______|     |__|    |__|

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\



