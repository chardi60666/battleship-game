#pragma once

#include <string>

class GameField {
public:
    GameField();
    std::string to_string(bool hide_ships) const;
};