#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <string.h>
#include <fcntl.h>

#include <iostream>

#include "header.h"
int main(int argc, char* argv[]){
    bool hex, bin;
    int length = -1, CC = -1, GR = -1;
    while(char opt = getopt(argc, argv, ":b:n:c:r:XB") != -1)
    {
     switch(opt)
     {
      case 'b':
         //use optarg for argument
         break;
       case 'n':
         length = atoi(optarg);
         break;
       case 'c':
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
        char *arr = NULL;
        char *arr2 = NULL;
        int fd = open(argv[i], O_RDONLY);
        if(fd == -1){perror("Cannot open file");return(-1);}
      
        if(strcmp(argv[optind], "-") == 0){
            for(j = 0; arr[j] != '\0'; j++){
                  arr2 = (char*)realloc(arr, (j + 1) * sizeof(char));
                  if(arr2 != NULL){
                      arr = arr2;
                      arr[j] = read(STDIN_FILENO, arr, 1);
                  }else{
                      free(arr);
                      perror("Cannot allocate memory");
                      return (-1);
                  }
            }
        }else{
            if(length != -1){
                for(j = 0; j < length; j++){
                  arr2 = (char*)realloc(arr, (j + 1) * sizeof(char));
                  if(arr2 != NULL){
                      arr = arr2;
                      arr[j] = read(fd, arr, 1);
                  }else{
                      free(arr);
                      perror("Cannot allocate memory");
                      return (-1);
                  }
                }
            }else{
                do{
                    j++;
                    arr2 = (char*)realloc(arr, j * sizeof(char));
                  if(arr2 != NULL){
                      arr = arr2;
                  }else{
                      free(arr);
                      perror("Cannot allocate memory");
                      return (-1);
                  }
                }while(read(fd, arr, 1) != 0);
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
    for(j = 0; arr[j] != '\0'; j++){
        std::cout << arr[j];
        write(STDOUT_FILENO, arr, 1);
    }
    free(arr);
    }
    return 0;
}
