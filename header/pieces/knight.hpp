#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.hpp"

class Knight : public Piece {
public:
  Knight(Color color);
  std::vector<Position> possibleMoves(const ChessBoard &board) override;
};
#endif
