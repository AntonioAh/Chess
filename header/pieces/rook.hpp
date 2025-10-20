#ifndef ROOK_H
#define ROOK_H

#include "piece.hpp"

class Rook : public Piece {
public:
  Rook(Color color);

  std::vector<Position> possibleMoves(const ChessBoard &board) override;

private:
};

#endif
