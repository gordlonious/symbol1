#ifndef convSequenceType_H
#define convSequenceType_H
#include "sequenceType.h"
#include <string>
class convSequenceType {
public:
  convSequenceType();
  convSequenceType(seqType type);
  std::string getTypeName();
private:
  //streamo errorInstance;
  void convertType(seqType type);
  seqType convType;
  std::string typeName;
};

#endif // !convSequenceType_H