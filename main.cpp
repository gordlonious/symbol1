#include <string>
#include <iostream>
#include "UnitTest0.h"
#include "arrCharTest.h"
int main(int arcg, char*argv[]) {
  UnitTestZero utz = UnitTestZero();
  std::cout << (4 == utz.testAllSymbol()) << " "; // symbol test all pass check
  std::cout << (utz.tCopySymbol());

  UTArrChar utac = UTArrChar();
  int ts = utac.tAllAC();
  std::cout << " " << ts;
  char stop;
  std::cout << std::endl;
  std::cout << "program has ended, please enter 'a' key..." << std::endl;
  std::cin >> stop;

  return 0;
}