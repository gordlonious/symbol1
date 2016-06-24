#ifndef topSearch_S
#define topSearch_S
#include <iostream>
#include "topSearch.h"
topSearch::topSearch() {
  tsFound = false;
  fContent = "";
  topsBuffer = "";
  tsErrorOutput = erroroutput();
  tsOStream = streamo();
}

topSearch::topSearch(fileReader &reader) {
  tsFound = false;
  fReader = reader;
  fContent = "";
  topsBuffer = "";
  tsErrorOutput = erroroutput();
  tsOStream = streamo();

  setFileName(); // careful
}

void topSearch::setFileName() {
  fileName = fReader.getFileName();
}

void topSearch::intakeWholeFile() {
  if (fileName != "") {
    fContent = fReader.dumpFile();
  }
  else {
    tsErrorOutput.changeErrMsg(" 'intake unsuccessful' ");
    tsErrorOutput.writeError();
  }
}

std::string topSearch::getContent() {
  return fContent;
}

std::string topSearch::displayFileName() {
  std::cout << "current 'topSearch' file name: ";
  std::cout << fileName << std::endl;
  return fileName;
}

// bigo:  O^2
bool topSearch::basic_linearSearch(std::string str) {
  int strL = str.length();
  int checkBumps = 0;
  for (int i = 0; i < fContent.length(); i++) {
    if (fContent[i] == str[0]) { // check for sequence
      for (int k = 0; k < strL; k++)
      {
        if (fContent[i + k] == str[k]) {
          checkBumps++;
        }
        if (checkBumps == strL) {
          return true;
        }
      }
    }
  }
  return false;
}

// bigo:  O(n)
bool topSearch::basic_linearSearch(char c) {
  if (fContent != "") {
    for (int i = 0; i < fContent.length(); i++) {
      if (fContent[i] == c) {
        return true;
      }
    }
    return false;
  } else {
    tsErrorOutput.changeErrMsg(" lSearch: NO CONTENT TO SEARCH FOR ");
    tsErrorOutput.writeError();
  }
}
#endif