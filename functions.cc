#include <cstdio>

#include "header.h"
const char* buffer_size(int N){
  
}
const char* change_bytes(char* msg[], int N){
  char buffer[N];
  howmany = read(fd, buffer, N);
  if(howmany == -1){perror("reading file - change_bytes"); return(-1);}
}
const char* caesar_cipher(char msg[], int k){ // does each word at a time
  for(int i = 0; msg[i] != '\0'; i++)
  {
    if(ch >= 'a' && ch <= 'z')
    {
      ch = ch + k;
      if(ch > 'z'){ch = ch - 'z' + 'a' -1;}
      msg[i] = ch;
    }
    else if (ch >= 'A' && ch <= 'Z')
    {
      ch = ch + k;
      if(ch > 'Z'){ch = ch - 'Z' + 'A' -1;}
      msg[i] = ch;
    }
  }
    
}
