#ifndef erroroutput_H
#define erroroutput_H
#include <string>
#include <array>
#include "streamo.h"
class erroroutput {
public:
  erroroutput();
  erroroutput(char* msg, char endToken);
  erroroutput(std::string msg);
  void writeError();
  void changeErrMsg(std::string msg, char* altMsg = NULL);
  ~erroroutput();
private:
  char charEndToken;
  char* charError;
  std::string strError;
  std::string standardErrorName;
};

#endif