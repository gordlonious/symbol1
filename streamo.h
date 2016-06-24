#ifndef streamo_H
#define streamo_H
#include <ostream>
#include <fstream>
#include "sequenceType.h"
#include "outputObjDev.h"
class streamo {
public:
  streamo();
  streamo(std::stringbuf &strBuffer, std::string fileName);
  streamo(std::filebuf &fBuffer, std::string fileName);
  ~streamo();

  void print(seqType seqT, outputOBjDev outputobj, std::string fileName);
private:
  std::ostream *fickleStream;

};

#endif