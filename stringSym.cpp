#ifndef stringSym_S
#define stringSym_S
#include <iostream>
#include "stringSym.h"

stringSym::stringSym() : arrayChar() { }

stringSym::stringSym(std::array<char, binMax::gim> &arr) {
  // range loop?
  for (size_t i = 0; i < arr.size(); i++) {
    strSym += arr[i];
  }
}

stringSym::stringSym(std::string sym) {
  strSym = sym;
}

#endif