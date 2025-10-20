#ifndef PAWN_H
#define PAWN_H

#include "piece.hpp"

class Pawn : public Piece {
public:
  Pawn(Color color);
  std::vector<Position> possibleMoves(const ChessBoard &board) override;
};
#endif
