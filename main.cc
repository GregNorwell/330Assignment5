#include <cstdio>

#include "header.h"
#include "functions.cc"
int main(int argc, char* argv[]){
  switch(getopt(argc, argv, ":b:n:C:r:XB")){
    case 'b':
      break;
    case 'n':
      break;
    case 'C':
      break;
    case 'r':
      break;
    case 'X':
      break;
    case 'B':
      break;
    case ':':
      perror("option needs a value");
      return(-1);
    case '?':
      perror("unknown option");
      return(-1);
  }
}
