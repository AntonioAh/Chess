#include "pieces/queen.hpp"
#include "chessboard.hpp"
#include "color.hpp"

Queen::Queen(Color color) : Piece(color, 9) {}

std::vector<Position> Queen::possibleMoves(const ChessBoard &board) {

  return {};
}
