#ifndef POSITION_H
#define POSITION_H

#include <cstddef>

#define DIM 8
#define SQUARED 64

class Position {
public:
  Position(short row, short col);
  Position(std::size_t index);

  short row();
  short column();
  std::size_t index();

private:
  const short _row, _column;
  const std::size_t _index;
};

#endif
