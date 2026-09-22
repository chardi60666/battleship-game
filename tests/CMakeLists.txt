include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
# Для MSVC на Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(unit_tests position_test.cpp)
target_link_libraries(unit_tests PRIVATE battleship_lib gtest_main)

include(GoogleTest)
gtest_discover_tests(unit_tests)