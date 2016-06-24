#ifndef stringSymProc_H
#define stringSymProc_H
#include "arrayCharSymbolProc.h"
const int string123456 = 65;

// inher prob
// I just templated my template which solved my error list 
//    error -> stringSymProc (in) obj file
template<int str>
class stringSymProc : public arrayCharSymbolProc<string123456> {
public:
  stringSymProc();
private:

};
#endif