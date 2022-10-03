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
  char *temp = new char[length * 2];
  int j = 0;
  
  while(i < length){std::cout << msg[i] << " ";i++;}
  std::cout << length;
  
  for(int i = 0; i < length; i++){
    temp[j] = msg[i] & 15;
    temp[j + 1] = msg[i] >> 4;
    j += 2;
  }
  msg = (char*)realloc(msg, (length * 2) * sizeof(char));
  for(int i = 0; i < (length * 2); i++)
    msg[i] = temp[i];
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
