#ifndef symbolProcessor_S
#define symbolProcessor_S
#include "symbolProcessor.h"
#include <array>
symbolProcessor::symbolProcessor() {
  sSeq = symbolSequence<ROUGH_symbolSequence_INT>();
  sSym = Symbol();
}

symbolProcessor::symbolProcessor(std::string sym) {
  if (sym.length() == 1) {
    sSym = Symbol(sym[0]);
  }
  else if (sym.length() > 1) {
    unsigned int const symL = sym.length();
    std::array<char, 10> str;
    for (unsigned int i = 0; i < sym.length(); i++) {
      str[i] = sym[i];
    }
    char endTok = sym.back();
    sSeq = symbolSequence<ROUGH_symbolSequence_INT>(str, endTok);
    useSequence = true;
  }
}

symbolProcessor::symbolProcessor(char c) {
  sSym = Symbol(c);
}

void symbolProcessor::getSymbolSequence(std::string &str) {
  str = sSeq.getSecureSeq();
}

void symbolProcessor::getSymbolChar(char &c) {
  c = sSym.getSymbol();
}

bool symbolProcessor::usingSequence() {
  return useSequence;
}

seqType symbolProcessor::getTypeOfSequence() {
  return sSeq.getvalSeqType();
}

seqType symbolProcessor::getTypeOfSymbol() {
  return sSym.get_symbol_type();
}
#endif