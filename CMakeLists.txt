cmake_minimum_required(VERSION 3.20)
project(battleship CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

# Собираем библиотеку с логикой игры
add_library(battleship_lib
        src/Position.cpp
)

# Собираем исполняемый файл (приложение)
add_executable(battleship_app src/main.cpp)
target_link_libraries(battleship_app PRIVATE battleship_lib)

# Подключаем тесты
enable_testing()
add_subdirectory(tests)