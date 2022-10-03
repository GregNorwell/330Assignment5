#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <string.h>
#include <fcntl.h>

#include <iostream>

#include "header.h"
int main(int argc, char* argv[])
{
    bool hex, bin;
    uint32_t arraySize = 1024;
    int buffer = 1, length = -1, CC = -1, GR = -1;
    while(char opt = getopt(argc, argv, ":b:n:c:r:XB") != -1)
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
        int j = 0;
        char *buffer = new char[arraySize];
        char *arr2 = NULL;
        int fd = open(argv[i], O_RDONLY);
        if(fd == -1)
        {
            perror("Cannot open file");return(-1);
        }
      
        if(strcmp(argv[optind], "-") == 0)
        {
            while((n = read(STDIN_FILENO, buffer, arraySize)) > 0){
                if(write(STDOUT_FILENO, buffer, j) != j){
                    perror("writing error");
                    return -1;
                }
            }
        }
        else
        {
            
        } 
        if(CC != -1)
        {
          caesar_cipher(arr, CC);
        }
        else if(GR != -1)
        {
          general_rotation(arr, GR);
        }
        if(hex == true)
        {
          hex_conversion(arr, j);
        }
        else if(bin == true)
        {
          bin_conversion(arr, j);
        }
       while((read(fd, arr, buffer)) > 0)
       { 
        write(STDOUT_FILENO, arr, j);
       }
       delete[] buffer;
       close(fd);
    }
       return 0;
}
