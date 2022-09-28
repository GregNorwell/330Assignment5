#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <string.h>
#include <fcntl.h>

#include "functions.cc"
int main(int argc, char* argv[]){
  bool hex, bin;
  int n, altBuffer, alt;
  int *arr = calloc(n, sizeof(char));
  if(arr == NULL){perror("Cannot allocate memory");return(-1);}
  
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
         hex = true;
         break;
       case 'B':
         bin = true;
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
  
  for(int i = optind; i < argc; i++)
  {
    file = argv[i];
    int fd = open(file, O_RDONLY);
    for(int i = 0; i < n; i++)
      arr + i = read(fd, arr, n);
  }
  
  //  write(STDOUT_FILENO, buf, n);
  free(arr);
}
