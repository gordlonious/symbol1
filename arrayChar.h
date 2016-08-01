#ifndef arrayChar_H
#define arrayChar_H
#include <array>
#include "binMax.h"

class arrayChar {
public:
  arrayChar();
  arrayChar(int size);
  arrayChar(arrayChar& ac);
  arrayChar(arrayChar&& ac);
  arrayChar(std::string sSym);
  arrayChar(std::array<char, binMax::gim>& sSym);
  void assign(char c, int index);

  unsigned int getStdSize();
  unsigned int getObjSize();
  bool clear();
private:
  int symSize;
  char endTok;
  std::array<char, binMax::gim> stdSym;
  char* customArray;
};
#endif