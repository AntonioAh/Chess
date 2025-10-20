#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "color.hpp"
#include "piece.hpp"
#include "position.hpp"
#include <array>
#include <memory>

class ChessBoard {
public:
  ChessBoard();
  bool move(Position from, Position to);
  std::shared_ptr<Piece> getPiece(Position &position) const;

  short getValue(Color color) const;
  std::vector<Position> possibleMoves(Position &from) const;

  std::shared_ptr<Piece> operator[](Position &pos) const;

private:
  std::array<std::shared_ptr<Piece>, SQUARED> _board;
  Color _turn;
  unsigned short _nMove;

  void _changeTurn();
  bool _checkRightColor(Position &pos);
  bool _validTarget(Position &target);
};

#endif // !CHESSBOARD_H
