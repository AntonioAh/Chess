#include "pieces/pawn.hpp"

Pawn::Pawn(Color color) : Piece(color, 1) {}

std::vector<Position> Pawn::possibleMoves(const ChessBoard &board) {
  return {};
}
