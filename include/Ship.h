#pragma once

class Ship {
private:
    int _length;
public:
    Ship();
    explicit Ship(int length);
    int get_length() const;
};