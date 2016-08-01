#ifndef UnitTest0_H
#define UnitTest0_H
#include "Symbol.h"
#include <assert.h>

// general class to test various other objects
class UnitTestZero {
public:
  UnitTestZero();
  int testAllSymbol();
  bool t0Symbol();
  bool t1Symbol();
  bool t2Symbol();
  bool t3Symbol();
  bool tCopySymbol();
  void LoadFunction(void(*func));
private:

};

UnitTestZero::UnitTestZero() { }

void UnitTestZero::LoadFunction(void(*func)) {
  //func();
}

bool UnitTestZero::tCopySymbol() {
  Symbol s = Symbol('c');
  Symbol c = Symbol(s);

  int allPass = 0;
  if (c.getMe() == s.getMe())
    allPass++;
  if (c.getSymbol() == s.getSymbol())
    allPass++;
  if (c.get_symbol_type() == s.get_symbol_type())
    allPass++;
  if (allPass == 3)
    return true;
  else
    return false;
}

int UnitTestZero::testAllSymbol() {
  int t = 0;
  if (this->t0Symbol())
    t++;
  if (this->t1Symbol())
    t++;
  if (this->t2Symbol())
    t++;
  if (this->t3Symbol())
    t++;

  return t;
}

bool UnitTestZero::t0Symbol() {
  Symbol s = Symbol('c');
  if (s.getSymbol() == 'c')
    return true;
}

bool UnitTestZero::t1Symbol() {
  Symbol s = Symbol('c');
  if (s.getSymbol() == 99)
    return true;
}

bool UnitTestZero::t2Symbol() {
  Symbol s = Symbol('c');
  if (s.getMe() == 'c')
    return true;
}

bool UnitTestZero::t3Symbol() {
  Symbol s = Symbol('c');
  if (s.getMe() == 99)
    return true;
}
#endif