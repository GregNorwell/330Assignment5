#include <cstdio>
#include <unistd.h>

#define BUFSIZ 1

#include "header.h"
#include "functions.cc"
int main(int argc, char* argv[]){
  char buf[BUFSIZ];
  int n;
  
  file = argv[optind];
  int fd = open(file, O_RDONLY);
  
    while((opt = getopt(argc, argv, ":b:n:C:r:XB")) != -1)
    {
     switch(opt)
     {
      case 'b':
         //use optarg for argument
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
       default:
         break;
     }
   }
  while((n = read(fd, buf, BUFSIZ)) > 0)
    write(STDOUT_FILENO, buf, n);
}
