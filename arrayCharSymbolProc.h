#ifndef arrayCharSymbolProc_H
#define arrayCharSymbolProc_H
#include "Symbol.h"
#include <array>

const int arrayCharSymbolProcMax = 100;
template<int sSize>
class arrayCharSymbolProc : Symbol {
public:
  arrayCharSymbolProc();
  arrayCharSymbolProc(int size);
  arrayCharSymbolProc(std::string sSym);
  arrayCharSymbolProc(std::array<char, sSize>& sSym, char endToken);
  unsigned int getSize();
private:
  int symSize;
  char endTok;
  std::array<char, sSize> symCharArr;
  int countSym();
};
#endif