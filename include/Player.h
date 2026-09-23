#pragma once

#include "Position.h"
#include "GameField.h"
#include "Ship.h"
#include <string>
#include <stdexcept>

enum State { Missed, BoatDestroyed, DestroyersDestroyed, CruisersDestroyed, BattleshipDestroyed, Hit };

class Player {
private:
    GameField _gamefield;
    int _ships_counts[4];

public:
    static const int _max_ships_counts[4];

    Player();

    void set_ship(const Ship& ship);
    State set_action(int row, char col);

    std::string show_field(bool hide_ships = false) const;
    bool check_lose() const;
    bool check_ready() const;
};