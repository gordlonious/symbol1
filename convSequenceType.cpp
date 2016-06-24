#ifndef convSequenceType_S
#define convSequenceType_S
#include "convSequenceType.h"

convSequenceType::convSequenceType(seqType type) {
  convertType(type);
}

std::string convSequenceType::getTypeName() {
  return typeName;
}

void convSequenceType::convertType(seqType type) {
  if (type == 0) {
    typeName = "escape";
  }
  else if (type == 1) {
    typeName = "unicode";
  }
  else if (type == 2) {
    typeName = "regular";
  }
}

convSequenceType::convSequenceType() {
  convertType(seqType::regular);
}
#endif