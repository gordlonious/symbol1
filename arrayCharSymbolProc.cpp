#ifndef arrayCharSymbolProc_S
#define arrayCharSymbolProc_S
#include "arrayCharSymbolProc.h"
#include <string>

// WHEN SHOULD SYMBOL BASES BE CREATED FOR SYMBOL SEQUENCES

template<int sSize>
arrayCharSymbolProc<sSize>::arrayCharSymbolProc() : Symbol() { symSize = arrayCharSymbolProcMax; }

template<int sSize>
arrayCharSymbolProc<sSize>::arrayCharSymbolProc(int size) : Symbol() { symSize = size; }

template<int sSize>
arrayCharSymbolProc<sSize>::arrayCharSymbolProc(std::string pSym) {
  for (unsigned int i = 0; i < pSym.size(); i++) {
    symCharArr[i] = pSym[i];
  }
}

template<int sSize>
arrayCharSymbolProc<sSize>::arrayCharSymbolProc(std::array<char, sSize>& sSym, char endToken) {
  /*endTok = endToken;
  int els = countSym();*/
}

template<int sSize>
unsigned int arrayCharSymbolProc<sSize>::getSize() {
  return symCharArr.size();
}

// size member should return exact # of els
//    unit testing
//template<int sSize>
//int arrayCharSymbolProc<sSize>::countSym() {
//  int i = 0;
//  while (i < sSize) {
//    if (symCharArr[i] == endTok) {
//      i++;
//      break;
//    }
//    i++;
//  }
//  return i;
//}

#endif