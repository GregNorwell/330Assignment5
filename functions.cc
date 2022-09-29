#include <cstdio>

#include "header.h"
void caesar_cipher(char msg[], int k){ // does each word at a time
  char ch;
  for(int i = 0; msg[i] != '\0'; i++)
  {
    ch = msg[i];
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
void general_rotation(char msg[], int k){
  char ch;
  for(int i = 0; msg[i] != '\0'; i++)
  {
    ch = msg[i];
    ch = ch + k;
    msg[i] = ch;
  }
}
void hex_conversion(char* msg[], int limit)
{
  
}
void bin_conversion(char* msg[], int limit)
{
  
}
