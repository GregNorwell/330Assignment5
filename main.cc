#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <string.h>
#include <fcntl.h>

#include "header.h"
int main(int argc, char* argv[]){
    bool hex, bin;
    int buffer = 1, length = -1, CC = -1, GR = -1;
    while(char opt = getopt(argc, argv, ":b:n:C:r:XB") != -1)
    {
     switch(opt)
     {
      case 'b':
         //use optarg for argument
         buffer = atoi(optarg);
         break;
       case 'n':
         length = atoi(optarg);
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
    int j;
    char *arr = (char*)calloc(1, sizeof(char));
    if(arr == NULL){perror("Cannot allocate memory");return(-1);}
    int fd = open(argv[i], O_RDONLY);
      
    if(strcmp(argv[optind], "-") == 0){
        for(j = 0; arr[j] != '\0'; j++){
            arr = (char*)realloc(arr, (j + buffer) * sizeof(char));
            arr[j] = read(STDIN_FILENO, arr, buffer);
        }
    }else{
        if(length != -1){
            for(j = 0; j < length; j++){
              arr = (char*)realloc(arr, (j + buffer) * sizeof(char));
              arr[j] = read(fd, arr, buffer);
            }
        }else{
            for(j = 0; arr[j] != '\0'; j++){
              arr = (char*)realloc(arr, (j + buffer) * sizeof(char));
              arr[j] = read(fd, arr, buffer);
            }
        }
    }
         
    if(CC != -1){
      caesar_cipher(arr, CC);
    }
    else if(GR != -1){
      general_rotation(arr, GR);
    }
    if(hex == true){
      hex_conversion(arr, j);
    }
    else if(bin == true){
      bin_conversion(arr, j);
    }
    write(STDOUT_FILENO, arr, j);
    free(arr);
  }
  return 0;
}
