#include "Position.h"
#include <cctype>
#include <random>

bool is_collision(int val) {
    return val < 1 || val > 10;
}

bool is_collision(char c) {
    char upper = std::toupper(static_cast<unsigned char>(c));
    return upper < 'A' || upper > 'J';
}

bool parse(const std::string& str, Position& pos) {
    std::string num_part;
    char alpha_part = '\0';

    for (char ch : str) {
        if (std::isspace(static_cast<unsigned char>(ch)) || ch == '/') continue;
        if (std::isdigit(static_cast<unsigned char>(ch))) {
            num_part += ch;
        } else if (std::isalpha(static_cast<unsigned char>(ch))) {
            alpha_part = ch;
        }
    }

    if (num_part.empty() || alpha_part == '\0') return false;

    int r = std::stoi(num_part);
    if (is_collision(r) || is_collision(alpha_part)) return false;

    pos._row = r;
    pos._col = std::toupper(static_cast<unsigned char>(alpha_part)) - 'A' + 1;
    return true;
}

Position::Position() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 10);
    _row = dist(gen);
    _col = dist(gen);
}

Position::Position(int r, int c) {
    row(r);
    col(c);
}

Position::Position(int r, char c) {
    row(r);
    col(c);
}

Position::Position(const std::string& str) {
    if (!parse(str, *this)) {
        throw std::logic_error("Invalid input: incorrect position");
    }
}

void Position::row(int r) {
    if (is_collision(r)) throw std::logic_error("Invalid input: incorrect position");
    _row = r;
}

void Position::col(int c) {
    if (is_collision(c)) throw std::logic_error("Invalid input: incorrect position");
    _col = c;
}

void Position::col(char c) {
    if (is_collision(c)) throw std::logic_error("Invalid input: incorrect position");
    _col = std::toupper(static_cast<unsigned char>(c)) - 'A' + 1;
}