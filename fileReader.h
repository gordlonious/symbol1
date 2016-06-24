#ifndef fileReader_H
#define fileReader_H
#include <fstream>

class fileReader {
public:
  fileReader();
  fileReader(std::filebuf &buf, std::string fileName); // opens file
  char fGetChar();
  void setFileName(std::string str);
  std::string dumpFile();
  std::string getFileName();
  void closeInputStream();
private:
  std::fstream *inputStream;
  std::string fileName;
};
#endif