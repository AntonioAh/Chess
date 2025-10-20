#include "pieces/rook.hpp"
#include "piece.hpp"
#include <vector>

Rook::Rook(Color color) : Piece(color, 5) {}

std::vector<Position> Rook::possibleMoves(const ChessBoard &board) {
  return {};
}
