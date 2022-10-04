#include <cstdio>
#include <cstdlib>

#include <iostream>

#include "header.h"
void caesar_cipher(char *& msg, int k){ // does each word at a time
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
void general_rotation(char *& msg, int k){
  char ch;
  for(int i = 0; msg[i] != '\0'; i++)
  {
    ch = msg[i];
    ch = ch + k;
    msg[i] = ch;
  }
}
void hex_conversion(char *& msg, int length)
{
  char *temp = new char[length];
  for(int i = 0; i < length; i++)
    temp[i] = msg[i];
  msg = (char*)realloc(msg, (length * 2) * sizeof(char));
  int j = 0;
  
  //for(int i = 0; i < length; ++i){std::cout << msg[i];}
  
  for(int i = 0; i < length; i++){
    msg[j] = int(temp[i]) & 15;
    std::cout << msg[j];
    msg[j + 1] = int(temp[i]) >> 4;
    std::cout << msg[j+ 1];
    j += 2;
  }
  //for(int i = 0; i < (length * 2); ++i){std::cout << msg[i];}
  delete[] temp;
}
void bin_conversion(char *& msg, int length)
{
  char *temp = new char[length * 8];
  int j = 0;
  
  for(int i = 0; i < length; i++){
    int val = int(msg[i]);
    while(val > 0){
      (val % 2)? temp[j] = '1' : temp[j] = '0';
      j++;
      val /= 2;
    }
  }
  msg = (char*)realloc(msg, (length * 8) * sizeof(char));
  for(int i = 0; i < (length * 8); i++)
    msg[i] = temp[i];
  delete[] temp;
}
