#ifndef topSearch_H
#define topSearch_H
#include <string>
#include "fileReader.h"
#include "streamo.h"
#include "erroroutput.h"
class topSearch {
public:
  topSearch();
  topSearch(fileReader &reader);
  void intakeWholeFile();
  std::string getContent();
  std::string displayFileName();
  bool basic_linearSearch(std::string str);
  bool basic_linearSearch(char c);
private:
  erroroutput tsErrorOutput;
  streamo tsOStream; // ts buffer
  fileReader fReader;
  bool tsFound;
  std::string fContent;
  std::string topsBuffer;

  // reader
  std::string fileName;
  void setFileName();
  
};
#endif