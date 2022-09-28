#include <cstdio>
#include <bitset>

#include "header.h"
const char* buffer_size(int N){
  
}
const char* change_bytes(char msg[], int N){
  
}
const char* caesar_cipher(char* msg[], int k){ // does each word at a time
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
    return msg;
}
const char* general_rotation(char* msg[], int k){
  char ch;
  for(int i = 0; msg[i] != '\0'; i++)
  {
    ch = msg[i];
    ch = ch + k;
    msg[i] = ch;
  }
  return msg;
}
const char* hex_conversion(char* msg[])
{
  
  
}
const char* bin_conversion(char* msg[])
{
  for(int i = 0; msg[i] != '\0'; i++)
    bitset<8>
}
