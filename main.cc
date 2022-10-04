#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <string.h>
#include <fcntl.h>

#include "header.h"
int main(int argc, char* argv[])
{
    char opt;
    bool hex = false, bin = false;
    int length = -1;
    int CC = -1, GR = -1;
    while((opt = getopt(argc, argv, ":b:n:c:r:XB")) != -1)
    {
     switch(opt)
     {
      case 'b':
         //use optarg for argument
         //altbuflength = atoi(optarg);
         //arraySize = altbuflength;
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
         return -1;
       case '?':
         perror("unknown option");
         return -1;
       default:
         break;
     }
    }
    for(int i = optind; i < argc; i++)
    {
        int j, size;
        char *buffer = new char[arraySize];
        if(strcmp(argv[i], "-") == 0)
        {
            while((j = read(STDIN_FILENO, buffer, 1)) > 0){
                if(write(STDOUT_FILENO, buffer, j) != j){
                    perror("writing error");
                    return -1;
                }
            }
        }
        else
        {
            int fd = open(argv[i], O_RDONLY); //open file in read only
            if(fd == -1){
                perror("Cannot open file");return(-1);
            }
            
            while((j = read(fd, buffer, 1)) > 0){
                size = j;
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
          hex_conversion(buffer, size);
          size = size * 2;
        }
        else if(bin == true)
        {
          bin_conversion(buffer, size);
          size = size * 8;
        }
        
        if(length != -1) //write if length limited
            write(STDOUT_FILENO, buffer, length);
        
        write(STDOUT_FILENO, buffer, size); // write otherwise
                    
       delete[] buffer; //free up space
    }
       return 0;
}
