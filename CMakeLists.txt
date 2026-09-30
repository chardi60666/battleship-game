cmake_minimum_required(VERSION 3.20)
project(battleship)

set(CMAKE_CXX_STANDARD 17)

# 1. Говорим CMake, где лежат все наши .h файлы
include_directories(include)

# 2. Собираем всю логику в одну библиотеку (как и требовалось в твоих начальных ошибках)
add_library(battleship_lib
        src/Position.cpp
        src/Ship.cpp
        src/GameField.cpp
        src/Player.cpp
)

# 3. Создаем исполняемый файл игры из main.cpp
add_executable(battleship_app src/main.cpp)

# 4. Привязываем нашу библиотеку с классами к исполняемому файлу
target_link_libraries(battleship_app battleship_lib)

# Если у тебя настроены тесты GoogleTest, раскомментируй строчку ниже:
# add_subdirectory(tests)