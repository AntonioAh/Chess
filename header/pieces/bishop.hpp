#ifndef BISHOP_H
#define BISHOP_H

#include "piece.hpp"

class Bishop : public Piece {
public:
  Bishop(Color color);
  std::vector<Position> possibleMoves(const ChessBoard &board) override;
};
#endif
