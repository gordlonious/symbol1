#include <string>
#include <iostream> // guard
#include "symbolSequence.h"
void main() {
  symbolSequence<10> symS1 = symbolSequence<10>();

  char stop;
  std::cout << "program has ended, please enter 'a' key..." << std::endl;
  std::cin >> stop;
}