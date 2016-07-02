#ifndef arrayChar_S
#define arrayChar_S
#include "arrayChar.h"
#include <string>

arrayChar::arrayChar() { 
  symSize = binMax::gim;
}

arrayChar::arrayChar(int size) { symSize = size; }

arrayChar::arrayChar(std::string pSym) {
  for (unsigned int i = 0; i < pSym.size(); i++) {
    stdSym[i] = pSym[i];
  }
}

arrayChar::arrayChar(std::array<char, binMax::gim>& sSym, char endToken) {
  for (unsigned int i = 0; i < sSym.size(); i++) {
    stdSym[i] = sSym[i];
  }
}

unsigned int arrayChar::getSize() {
  return stdSym.size();
}

bool arrayChar::clear() {
  stdSym.fill('0');
  return true; // test?
}

#endif