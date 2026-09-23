#include "GameField.h"

GameField::GameField() {
    // Конструктор поля
}

std::string GameField::to_string(bool hide_ships) const {
    // Возвращаем пустую сетку по формату Степика
    return "|A B C D E F|\n+-----------+\n1 | . | . | . |\n+-----------+";
}