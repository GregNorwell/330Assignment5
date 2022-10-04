#include <cstdio>
#include <cstdlib>

#include <iostream>

#include "header.h"
void caesar_cipher(char *& msg, int k){ 
  char ch;
  for(int i = 0; msg[i] != '\0'; i++)
  {
    ch = msg[i];
    if(ch >= 'a' && ch <= 'z')//lower case
    {
      ch = ch + k;
      if(ch > 'z'){ch = ch - 'z' + 'a' -1;}
      msg[i] = ch;
    }
    else if (ch >= 'A' && ch <= 'Z')//uppercase
    {
      ch = ch + k;
      if(ch > 'Z'){ch = ch - 'Z' + 'A' -1;}
      msg[i] = ch;
    }
  }
}
void general_rotation(char *& msg, int k){
  char ch;
  for(int i = 0; msg[i] != '\0'; i++)//general rotation: work 255+
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
  static const char hex_digits[] = "0123456789ABCDEF";
  msg = (char*)realloc(msg, (length * 2) * sizeof(char));
  int j = 0;
  
  //for(int i = 0; i < length; ++i){std::cout << msg[i];}
  
  for(int i = 0; i < length; i++){
    msg[j] = hex_digits[int(temp[i]) >> 4];
    //std::cout << int(msg[j]);
    msg[j + 1] = hex_digits[int(temp[i]) & 15];
    //std::cout << int(msg[j+ 1]);
    j += 2;
  }
  //for(int i = 0; i < (length * 2); ++i){std::cout << msg[i];}
  delete[] temp;
}
void bin_conversion(char *& msg, int length)
{
  char *temp = new char[length];
  for(int i = 0; i < length; i++)
    temp[i] = msg[i];
  msg = (char*)realloc(msg, (length * 8) * sizeof(char));
  int j = 0, val;

  for(int i = 0; i < length; i++){
    val = int(temp[i]); // convert char to ascii value
    while(val > 0){ // convert ascii to binary
      (val % 2)? msg[j] = '1' : msg[j] = '0';
      j++;
      val /= 2;
    }
  }
  
  delete[] temp;
}
