#ifndef header_H
#define header_H

//apply Caesar cipher to k alphabetical characters
void caesar_cipher(char *& msg, int k);
//general rotation shifting all characters k times
void general_rotation(char *& msg, int k);
//output data from file in hexadecimal format
void hex_conversion(char *& msg, int length);
//output data from the file in binary notation
void bin_conversion(char *& msg, int length);

#endif
