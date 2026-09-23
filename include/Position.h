#pragma once

#include <string>
#include <stdexcept>

#ifndef TEST_1
#define TEST_1
#endif

#ifndef TEST_2
#define TEST_2
#endif

class Position {
private:
    int _row;
    int _col;

    static const int _max_row = 10;
    static const int _max_col = 10;

public:
    Position();
    Position(int r, int c);
    Position(int r, char c);
    Position(const Position& other) = default;
    explicit Position(const std::string& str);

    [[nodiscard]] int row() const noexcept { return _row; }
    [[nodiscard]] int col() const noexcept { return _col; }
    [[nodiscard]] char char_col() const noexcept { return static_cast<char>('A' + _col - 1); }

    void row(int r);
    void col(int c);
    void col(char c);

    friend bool parse(const std::string& str, Position& pos);
    friend bool is_collision(int val) TEST_2;
    friend bool is_collision(char c) TEST_2;

    TEST_1
};

bool is_collision(int val);
bool is_collision(char c);
bool parse(const std::string& str, Position& pos);