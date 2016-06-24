#ifndef Symbol_H
#define Symbol_H
#include "convSequenceType.h"
#include "sequenceType.h"
#include "char_Symbol_Base.h"
class Symbol : public char_Symbol_Base {
public:
  Symbol();
  Symbol(char c);
  Symbol(Symbol &s);
  ~Symbol();
  char getSymbol();
  seqType get_symbol_type();
  virtual bool isPlural();
private:
  bool isEscape();
  seqType symT;
};

#endif