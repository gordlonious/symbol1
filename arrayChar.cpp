#ifndef arrayChar_S
#define arrayChar_S
#include "arrayChar.h"
#include <string>

arrayChar::arrayChar() { 
  symSize = binMax::gim;
}

arrayChar::arrayChar(int size) { symSize = size; }

// symSize is counted
arrayChar::arrayChar(std::string pSym) {
  symSize = 0;
  for (unsigned int i = 0; i < pSym.size(); i++) {
    stdSym[i] = pSym[i];
    symSize += 1;
  }
}

// symSize is defaulted to binMax::gim or 32
arrayChar::arrayChar(std::array<char, binMax::gim>& sSym) {
  symSize = binMax::gim;
  for (unsigned int i = 0; i < sSym.size(); i++) {
    stdSym[i] = sSym[i];
  }
}

// std::array container is used to get the size
unsigned int arrayChar::getStdSize() {
  return stdSym.size();
}

unsigned int arrayChar::getObjSize() {
  return symSize;
}

//bool arrayChar::clear() {
//  stdSym.fill('0');
//  return true; // test?
//}

//copy constructors
//  size is copied
//arrayChar::arrayChar(arrayChar& ac) {
//  int paraSize = ac.getSize();
//  int index = 0;
//  for (char c : ac.stdSym) {
//    stdSym[index] = c;
//    index++;
//  }
//}
//
//arrayChar::arrayChar(arrayChar&& ac) {
//  int paraSize = ac.getSize();
//  int index = 0;
//  for (char c : ac.stdSym) {
//    stdSym[index] = c;
//    index++;
//  }
//}

#endif