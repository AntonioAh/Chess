#include "pieces/king.hpp"
#include "piece.hpp"

King::King(Color color) : Piece(color, 0) {}

std::vector<Position> King::possibleMoves(const ChessBoard &board) {
  return {};
}
