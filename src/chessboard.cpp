#include "chessboard.hpp"

#include "color.hpp"
#include "pieces/bishop.hpp"
#include "pieces/king.hpp"
#include "pieces/knight.hpp"
#include "pieces/pawn.hpp"
#include "pieces/queen.hpp"
#include "pieces/rook.hpp"
#include "position.hpp"
#include <cstddef>
#include <memory>
#include <sys/_pthread/_pthread_types.h>
#include <vector>

ChessBoard::ChessBoard() {
  _nMove = 0;
  _turn = Color::WHITE;

  for (int i = 0; i < DIM; i++) {
    Position whitePos(1, i), blackPos(6, i);
    _board[whitePos.index()] = std::make_shared<Pawn>(Color::WHITE);
    _board[blackPos.index()] = std::make_shared<Pawn>(Color::BLACK);
  }

  _board[0] = std::make_shared<Rook>(Color::WHITE);
  _board[1] = std::make_shared<Bishop>(Color::WHITE);
  _board[2] = std::make_shared<Knight>(Color::WHITE);
  _board[3] = std::make_shared<King>(Color::WHITE);
  _board[4] = std::make_shared<Queen>(Color::WHITE);
  _board[5] = std::make_shared<Bishop>(Color::WHITE);
  _board[6] = std::make_shared<Knight>(Color::WHITE);
  _board[7] = std::make_shared<Rook>(Color::WHITE);

  _board[56] = std::make_shared<Rook>(Color::BLACK);
  _board[57] = std::make_shared<Bishop>(Color::BLACK);
  _board[58] = std::make_shared<Knight>(Color::BLACK);
  _board[59] = std::make_shared<King>(Color::BLACK);
  _board[60] = std::make_shared<Queen>(Color::BLACK);
  _board[61] = std::make_shared<Bishop>(Color::BLACK);
  _board[62] = std::make_shared<Knight>(Color::BLACK);
  _board[63] = std::make_shared<Rook>(Color::BLACK);
}

void ChessBoard::_changeTurn() {
  if (_turn == Color::WHITE) {
    _turn = Color::BLACK;
    return;
  }

  _turn = Color::WHITE;
}

bool ChessBoard::_checkRightColor(Position &position) {
  std::size_t index = position.index();
  if (!_board[index])
    return false;

  return _board[index]->color() == _turn;
}

bool ChessBoard::_validTarget(Position &position) {
  std::size_t index = position.index();
  if (!_board[index])
    return true;

  return _board[index]->color() != _turn;
}

short ChessBoard::getValue(Color color) const {
  short tot = 0;
  for (int i = 0; i < SQUARED; i++) {
    if (_board[i] && _board[i]->color() == color)
      tot += _board[i]->value();
  }
  return tot;
}

std::vector<Position> ChessBoard::possibleMoves(Position &from) const {
  std::size_t index = from.index();
  if (!_board[index])
    return {};

  return _board[index]->possibleMoves(*this);
}

std::shared_ptr<Piece> ChessBoard::operator[](Position &pos) const {
  std::size_t index = pos.index();
  return _board[index];
}
