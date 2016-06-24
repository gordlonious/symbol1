#ifndef streamo_S
#define streamo_S
#include "streamo.h"

streamo::streamo() { fickleStream = NULL; }

// use customized buffer instead
streamo::streamo(std::stringbuf &strBuf, std::string fileName) {
  /*strBuf.open(fileName, std::ios::out);
  fickleStream = new std::ostream(&strBuf);*/
}

streamo::streamo(std::filebuf &fBuffer, std::string fileName) {
  fBuffer.open(fileName, std::ios::out);
  fickleStream = new std::ostream(&fBuffer);
}

streamo::~streamo() {
  delete fickleStream;
}

void streamo::print(seqType seq, outputOBjDev outputObj, std::string fileName) {
  if (outputObj == outputOBjDev::file) {

  }
  else { // is cout
    
  }
}

#endif // !streamo_H