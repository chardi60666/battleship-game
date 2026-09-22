#pragma once
#include <string>
#include <stdexcept>
#define TEST_1
#define TEST_2
class Position {
    int _row, _col;
    static const int _max_row = 10, _max_col = 10;
public:
    Position(int r = 1, int c = 1) : _row(r), _col(c) {}
    Position(int r, char c) : _row(r), _col(c - 'A' + 1) {}
    explicit Position(const std::string& str) { _row = 1; _col = 1; /* заглушка parse */ }
    int row() const { return _row; }
    int col() const { return _col; }
    char char_col() const { return 'A' + _col - 1; }
    void row(int r) { _row = r; }
    void col(int c) { _col = c; }
    void col(char c) { _col = c - 'A' + 1; }
};


