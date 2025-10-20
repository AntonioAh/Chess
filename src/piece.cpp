#include "piece.hpp"

Piece::Piece(Color color, short value) : _color(color), _value(value) {}

Color Piece::color() const { return _color; }

short Piece::value() const { return _value; }
