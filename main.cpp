#include <string>
#include <iostream>
#include "UnitTest0.h"
int main(int arcg, char*argv[]) {
  UnitTestZero utz = UnitTestZero();
  std::cout << (4 == utz.testAllSymbol()) << " "; // symbol test all pass check
  std::cout << (utz.tCopySymbol());
  char stop;
  std::cout << std::endl;
  std::cout << "program has ended, please enter 'a' key..." << std::endl;
  std::cin >> stop;

  return 0;
}