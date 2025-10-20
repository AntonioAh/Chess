#ifndef QUEEN_H
#define QUEEN_H

#include "piece.hpp"

class Queen : public Piece {
public:
  Queen(Color color);
  std::vector<Position> possibleMoves(const ChessBoard &board) override;
};
#endif
