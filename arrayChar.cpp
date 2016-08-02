#ifndef arrayChar_S
#define arrayChar_S
#include "arrayChar.h"
#include <string>

template<unsigned int _size>
arrayChar<_size>::arrayChar() { 
  symSize = binMax::gim;
}

template<unsigned int _size>
arrayChar<_size>::arrayChar(int size) { symSize = size; }

// symSize is counted
template<unsigned int _size>
arrayChar<_size>::arrayChar(std::string pSym) {
  symSize = 0;
  for (unsigned int i = 0; i < pSym.size(); i++) {
    stdSym[i] = pSym[i];
    symSize += 1;
  }
}

//// symSize is defaulted to binMax::gim or 32
template<unsigned int _size>
arrayChar<_size>::arrayChar(std::array<char, binMax::gim>& sSym) {
  symSize = binMax::gim;
  for (unsigned int i = 0; i < sSym.size(); i++) {
    stdSym[i] = sSym[i];
  }
}

//// std::array container is used to get the size
template<unsigned int _size>
unsigned int arrayChar<_size>::getStdSize() {
  return stdSym.size();
}

template<unsigned int _size>
unsigned int arrayChar<_size>::getObjSize() {
  return symSize;
}

template<unsigned int _size>
bool arrayChar<_size>::clear() {
  stdSym.fill('0');
  return true; // test?
}

////copy constructors
////  size is copied
template<unsigned int _size>
arrayChar<_size>::arrayChar(arrayChar& ac) {
  int paraSize = ac.getStdSize(); // size must be compatible
  int index = 0;
  for (char c : ac.stdSym) {
    stdSym[index] = c;
    index++;
  }
}

template<unsigned int _size>
arrayChar<_size>::arrayChar(arrayChar&& ac) {
  int paraSize = ac.getStdSize();  // size must be compatible
  int index = 0;
  for (char c : ac.stdSym) {
    stdSym[index] = c;
    index++;
  }
}

#endif