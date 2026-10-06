cmake_minimum_required(VERSION 3.20)
project(battleship)

set(CMAKE_CXX_STANDARD 17)


include_directories(include)


add_library(battleship_lib
        src/Position.cpp
        src/Ship.cpp
        src/GameField.cpp
        src/Player.cpp
)


add_executable(battleship_app src/main.cpp)


target_link_libraries(battleship_app battleship_lib)


# add_subdirectory(tests)
