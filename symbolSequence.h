#ifndef symbolSequence_HS
#define symbolSequence_HS
#include <string>
#include <iostream>
#include "Symbol.h"
#include "erroroutput.h"
#include <array>

const int ROUGH_symbolSequence_INT = 10;


template<int ROUGH_symbolSequence_INT>
class symbolSequence : public Symbol {
public:
  symbolSequence();
  symbolSequence(char* seq, char endingToken);
  symbolSequence(std::array<char, ROUGH_symbolSequence_INT> seq, char endingToken);


  std::string getSecureSeq();
  std::string getSeqTypeName();
  seqType getvalSeqType();
  void printType(bool endLine = false);
private:
  // creation
  void classifySequence(char* seq, char endTok);
  void classifySequence(std::array<char, ROUGH_symbolSequence_INT> seq, char endTok);
  void verifySequence(char* seq, char endTok);
  void verifySequence(std::array<char, ROUGH_symbolSequence_INT> seq, char endTok);


  bool validSequence;
  seqType seqObjType;
  bool isSingle(char *c);
  bool isSingle(std::array<char, ROUGH_symbolSequence_INT> c);
  std::string secureSeq;
  streamo outputStream;
};

template<int ROUGH_symbolSequence_INT>
seqType symbolSequence<ROUGH_symbolSequence_INT>::getvalSeqType() {
  return seqObjType;
}

// invalid if not sequence
template<int ROUGH_symbolSequence_INT>
symbolSequence<ROUGH_symbolSequence_INT>::symbolSequence(std::array<char, ROUGH_symbolSequence_INT> str, char endingToken) : Symbol(str[0]) {
  seqObjType = seqType::regular;
  outputStream = streamo();
  if (isSingle(str)) {
    validSequence = false;
  }
  else {
    validSequence = true;
    classifySequence(str, endingToken);
    verifySequence(str, endingToken);
  }
}

template<int ROUGH_symbolSequence_INT>
symbolSequence<ROUGH_symbolSequence_INT>::symbolSequence(char* str, char endingToken) : Symbol(str[0]) {
  seqObjType = seqType::regular;
  outputStream = streamo();
  if (isSingle(str)) {
    validSequence = false;
  }
  else {
    validSequence = true;
    classifySequence(str, endingToken);
    verifySequence(str, endingToken);
  }
}

template<int ROUGH_symbolSequence_INT>
void symbolSequence<ROUGH_symbolSequence_INT>::classifySequence(std::array<char, ROUGH_symbolSequence_INT> str, char endingToken) {
  bool single = isSingle(str);
  if (single) {
    validSequence = false;
  }
  else {
    validSequence = true;
  }
  // WARNING -- rough approximation of sequence classifications ( loose definition )
  if (validSequence) {
    int travStr = 0;
    char tokRef = str[travStr];
    seqObjType = regular;
    while (tokRef != endingToken) { // could cause traversal of unallocated memory
      if (tokRef == '\\') {
        seqObjType = escape;
      }
      if (tokRef > 127) {
        seqObjType = unicode;
      }
      travStr++;
      tokRef = str[travStr];
      if (travStr >= ROUGH_symbolSequence_INT) {
        erroroutput stopComp1 = erroroutput("template christ"); // write to
        break;
      }
    }
  }
}

template<int ROUGH_symbolSequence_INT>
void symbolSequence<ROUGH_symbolSequence_INT>::classifySequence(char* str, char endingToken) {
  bool single = isSingle(str);
  if (single) {
    validSequence = false;
  }
  else {
    validSequence = true;
  }
  // WARNING -- rough approximation of sequence classifications ( loose definition )
  if (validSequence) {
    int travStr = 0;
    char tokRef = str[travStr];
    seqObjType = regular;
    while (tokRef != endingToken) { // could cause traversal of unallocated memory
      if (tokRef == '\\') {
        seqObjType = escape;
      }
      if (tokRef > 127) {
        seqObjType = unicode;
      }
      travStr++;
      tokRef = str[travStr];
      if (travStr >= ROUGH_symbolSequence_INT) {
        erroroutput stopComp1 = erroroutput("template christ"); // write to
        break;
      }
    }
  }
}

template<int ROUGH_symbolSequence_INT>
std::string symbolSequence<ROUGH_symbolSequence_INT>::getSeqTypeName() {
  //return convType.getTypeName();
  return "";
}

template<int ROUGH_symbolSequence_INT>
bool symbolSequence<ROUGH_symbolSequence_INT>::isSingle(char *c) {
  char *nextC = &*(c + 1);
  if (nextC != NULL) {
    return false;
  }
  else {
    return true;
  }
}

template<int ROUGH_symbolSequence_INT>
bool symbolSequence<ROUGH_symbolSequence_INT>::isSingle(std::array<char, ROUGH_symbolSequence_INT> c) {
  if (c[1] > 0 || c[1] < 255) { // mm
    return false;
  }
  else {
    return true;
  }
}

template<int ROUGH_symbolSequence_INT>
std::string symbolSequence<ROUGH_symbolSequence_INT>::getSecureSeq() {
  return secureSeq;
}

template<int ROUGH_symbolSequence_INT>
void symbolSequence<ROUGH_symbolSequence_INT>::verifySequence(char* str, char endingToken) {
  // escape sequence
  for (int i = 0; i < ROUGH_symbolSequence_INT; i++) {
    // shitty integer security..
    if (str[i] < 0 || str[i] > 127) {
      //output crappy 'unicode' binary...
      seqObjType = seqType::unicode;
    }
    else {
      if (str[i] == endingToken) {
        break;
      }
      secureSeq += str[i]; // not secure
    }
  }
}

template<int ROUGH_symbolSequence_INT>
void symbolSequence<ROUGH_symbolSequence_INT>::verifySequence(std::array<char, ROUGH_symbolSequence_INT> str, char endingToken) {
  // escape sequence
  for (int i = 0; i < ROUGH_symbolSequence_INT; i++) {
    // shitty integer security..
    if (str[i] < 0 || str[i] > 127) {
      //output crappy 'unicode' binary...
      seqObjType = seqType::unicode;
    }
    else {
      if (str[i] == endingToken) {
        break;
      }
      secureSeq += str[i]; // not secure
    }
  }
}

template<int ROUGH_symbolSequence_INT>
void symbolSequence<ROUGH_symbolSequence_INT>::printType(bool endLine) {
  //std::cout << convType.getTypeName();
}

template<int ROUGH_symbolSequence_INT>
symbolSequence<ROUGH_symbolSequence_INT>::symbolSequence() {
  validSequence = false;
  seqObjType = seqType::noType;
}
#endif