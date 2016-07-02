#ifndef stringSym_H
#define stringSym_H
#include "arrayChar.h"

class stringSym : public arrayChar {
public:
  stringSym();
  stringSym(std::array<char, binMax::gim> &arChar);
  stringSym(std::string str);
private:
  std::string strSym;
};
#endif