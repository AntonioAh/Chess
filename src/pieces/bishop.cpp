#include "pieces/bishop.hpp"
#include "chessboard.hpp"

Bishop::Bishop(Color color) : Piece(color, 3) {}

std::vector<Position> Bishop::possibleMoves(const ChessBoard &board) {
  return {};
}
