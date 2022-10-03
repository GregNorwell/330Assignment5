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
    //int buffer, length = -1
    int CC = -1, GR = -1;
    while(char opt = getopt(argc, argv, ":b:n:c:r:XB") != -1)
    {
     switch(opt)
     {
      case 'b':
         //use optarg for argument
         //buffer = atoi(optarg);
         break;
       case 'n':
         //length = atoi(optarg);
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
        if(strcmp(argv[i], "-") == 0)
        {
            while((j = read(STDIN_FILENO, buffer, arraySize)) > 0){
                
            }
        }
        else
        {
            int fd = open(argv[i], O_RDONLY);
            if(fd == -1){
                perror("Cannot open file");return(-1);
            }
            
            while((j = read(fd, buffer, arraySize)) > 0){
                
            }
            
            close(fd);
        } 
        if(CC != -1)
        {
          caesar_cipher(buffer, CC);
        }
        else if(GR != -1)
        {
          general_rotation(buffer, GR);
        }
        if(hex == true)
        {
          hex_conversion(buffer, j);
        }
        else if(bin == true)
        {
          bin_conversion(buffer, j);
        }
       
       delete[] buffer;
    }
       return 0;
}
