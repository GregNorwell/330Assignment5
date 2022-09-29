#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <string.h>
#include <fcntl.h>

#include "header.h"
int main(int argc, char* argv[]){
    bool hex, bin;
    int n = 0; altBuffer = -1, altLength = -1, CC = -1, GR = -1;
    while((opt = getopt(argc, argv, ":b:n:C:r:XB")) != -1)
    {
     switch(opt)
     {
      case 'b':
         //use optarg for argument
         altBuffer = atoi(optarg);
         break;
       case 'n':
         altLength = atoi(optarg);
         break;
       case 'C':
         CC = atoi(optarg);
         break;
       case 'r':
         GR = atoi(optarg);
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
    int *arr = calloc(n, sizeof(char));
    if(arr == NULL){perror("Cannot allocate memory");return(-1);}
    
    file = argv[i];
    int fd = open(file, O_RDONLY);
    for(int i = 0; i < n; i++){
      arr = realloc((arr, (n + 1) * sizeof(char));
      arr[i] = read(fd, arr, n);
    }
    
    if(altBuffer != -1){
    }
    else if(altLength != -1){
    }
    else if(CC != -1){
      caesar_cipher(file, CC);
    }
    else if(GR != -1){
      general_rotation(file, GR)
    }
    else if(hex == true){
    }
    else if(bin == true){
    }
    write(STDOUT_FILENO, arr, n);
    free(arr);
  }
  
}
