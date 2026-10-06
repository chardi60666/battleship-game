#include "Ship.h"

Ship::Ship() : _length(1) {}

Ship::Ship(int length) : _length(length) {}

int Ship::get_length() const noexcept {
    return _length;
}
