#include "position.hpp"

Position::Position(short row, short col)
    : _row(row), _column(col), _index(row * DIM + col) {}

Position::Position(std::size_t index)
    : _row(index / DIM), _column(index % DIM), _index(index) {}

short Position::row() { return _row; }

short Position::column() { return _column; }

std::size_t Position::index() { return _index; }
