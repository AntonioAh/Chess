#ifndef KING_H
#define Knight_H

#include "piece.hpp"

class King : public Piece {
public:
  King(Color color);
  std::vector<Position> possibleMoves(const ChessBoard &board) override;
};
#endif
