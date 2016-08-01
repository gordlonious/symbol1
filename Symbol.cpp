#ifndef Symbol_S
#define Symbol_S
#include "Symbol.h"
// symbol must be single or escape
Symbol::Symbol() {
  symT = seqType::noType;
}

// default to regular with char construction
Symbol::Symbol(char c) : char_Symbol_Base(c) {
  symT = seqType::regular;
}

Symbol::~Symbol() {
  // no pointer members
}

// copy constructor
Symbol::Symbol(Symbol &s) : char_Symbol_Base(s.getSymbol()) { 
  symT = s.get_symbol_type();
}

char Symbol::getSymbol() {
  return getMe();
}

bool Symbol::isEscape() {
  if (getSymbol() != 0) { // null val??
    if (getSymbol() == '\\') {
      return true;
    }
    else {
      return false;
    }
  }
  else {
    return false;
  }
}

seqType Symbol::get_symbol_type() {
  return symT;
}

bool Symbol::isPlural() {
  return false;
}

// NOTE:
//  MAKE ascii matrix and operations compatible with Symbol
#endif