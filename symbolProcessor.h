#ifndef symbolProcessor_H
#define symbolProcessor_H
#include <string>
#include "symbolSequence.h"
class symbolProcessor {
public:
  symbolProcessor();
  symbolProcessor(std::string sym);
  symbolProcessor(char c);
  void getSymbolSequence(std::string &str);
  void getSymbolChar(char &c);
  bool usingSequence();
  seqType getTypeOfSequence();
  seqType getTypeOfSymbol();
private:
  bool useSequence;
  symbolSequence<ROUGH_symbolSequence_INT> sSeq;
  Symbol sSym;
};

#endif