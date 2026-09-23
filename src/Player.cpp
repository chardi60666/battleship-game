#include "Player.h"

const int Player::_max_ships_counts[4] = {4, 3, 2, 1};

Player::Player() {
    for (int i = 0; i < 4; ++i) {
        _ships_counts[i] = 0;
    }
}

void Player::set_ship(const Ship& ship) {
    // В рамках Степика здесь логика размещения корабля
}

State Player::set_action(int row, char col) {
    if (is_collision(row) || is_collision(col)) {
        throw std::logic_error("Invalid input: incorrect move");
    }
    return State::Missed;
}

std::string Player::show_field(bool hide_ships) const {
    std::string result = _gamefield.to_string(hide_ships);
    result += "\nShips Left:\n";
    result += "* - " + std::to_string(_max_ships_counts[0] - _ships_counts[0]) + " ";
    result += "** - " + std::to_string(_max_ships_counts[1] - _ships_counts[1]) + " ";
    result += "*** - " + std::to_string(_max_ships_counts[2] - _ships_counts[2]) + " ";
    result += "**** - " + std::to_string(_max_ships_counts[3] - _ships_counts[3]);
    return result;
}

bool Player::check_lose() const {
    for (int i = 0; i < 4; ++i) {
        if (_ships_counts[i] < _max_ships_counts[i]) return false;
    }
    return true;
}

bool Player::check_ready() const {
    for (int i = 0; i < 4; ++i) {
        if (_ships_counts[i] != _max_ships_counts[i]) return false;
    }
    return true;
}