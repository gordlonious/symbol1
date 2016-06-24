#ifndef char_Symbol_Base_S
#define char_Symbol_Base_S
#include "char_Symbol_Base.h"

char_Symbol_Base::char_Symbol_Base() {
  privChar = 0;
}

char_Symbol_Base::char_Symbol_Base(char c) {
  privChar = c;
}

char char_Symbol_Base::getMe() {
  return privChar;
}

#endif // !char_Symbol_Base_S