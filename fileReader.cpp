#ifndef fileReader_S
#define fileReader_S
#include "fileReader.h"
fileReader::fileReader() { inputStream = NULL; }

fileReader::fileReader(std::filebuf &buf, std::string fileName) {
  //buf.open(fileName, std::ios::in); // opened buffer with filename ( more research )
  //inputStream = new std::istream(&buf);
  inputStream = new std::fstream(fileName, std::ios::in);

  setFileName(fileName);
}

char fileReader::fGetChar() {
  return inputStream->get();
}

std::string fileReader::dumpFile() {
  std::string dumpster;
  while (!inputStream->eof()) {
    dumpster += inputStream->get();
  }
  // last day
  return dumpster;
}

std::string fileReader::getFileName() {
  return fileName;
}

void fileReader::setFileName(std::string str) {
  fileName = str;
}

void fileReader::closeInputStream() {
  
}
#endif