#ifndef PIECE_H
#define PIECE_H

#include "color.hpp"
#include "position.hpp"
#include <vector>

class ChessBoard;

class Piece {
public:
  Piece(Color color, short value);

  short value() const;
  Color color() const;

  virtual std::vector<Position> possibleMoves(const ChessBoard &board) = 0;

private:
  const short _value;
  const Color _color;
};

#endif
