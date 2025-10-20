#include "pieces/knight.hpp"
#include "piece.hpp"
#include <vector>

Knight::Knight(Color color) : Piece(color, 3) {}

std::vector<Position> Knight::possibleMoves(const ChessBoard &board) {
  return {};
}
