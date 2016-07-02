#ifndef arrayChar_H
#define arrayChar_H
#include <array>
#include "binMax.h"

class arrayChar {
public:
  arrayChar();
  arrayChar(int size);
  arrayChar(std::string sSym);
  arrayChar(std::array<char, binMax::gim>& sSym, char endToken);
  unsigned int getSize();
  bool clear();
private:
  int symSize;
  char endTok;
  std::array<char, binMax::gim> stdSym;
};
#endif