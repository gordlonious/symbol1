#ifndef erroroutput_S
#define erroroutput_S
#include <fstream>
#include "erroroutput.h"

erroroutput::erroroutput() {
  standardErrorName = "standardError";
}

erroroutput::erroroutput(std::string msg) {
  standardErrorName = "standardError";
  strError = msg;
}

erroroutput::erroroutput(char* msg, char endToken) {
  standardErrorName = "standardError";
  strError = "";

  // convert char* msg to std::string type
  int charI = 0;
  while (msg[charI] != endToken) {
    strError += msg[charI];
    charI++;
  }
}

erroroutput::~erroroutput() {
  //delete charError;
}

void erroroutput::writeError() {
  std::fstream inlineFstream;
  inlineFstream.open(standardErrorName, std::ios::out);
  if (strError != "") {
    inlineFstream << "  STR: " << strError;
  }
  else if (charError != NULL) {
    inlineFstream << "  'char* support needed'";
  }
  else {
    inlineFstream << " There was no msg ";
  }
}

void erroroutput::changeErrMsg(std::string msg, char* msg2) {
  if (msg != "") {
    strError = msg;
  } else if(msg2 != NULL) {
    int charI = 0;
    while (msg2[charI] != charEndToken) {
      strError += msg2[charI];
      charI++;
    }
  }
}

#endif