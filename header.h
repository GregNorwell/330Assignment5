#ifndef header_H
#define header_H

//change buffer size N amount
const char* buffer_size(int N);
//change bytes read to N from each file
const char* change_bytes(int N);
//apply Caesar cipher to k alphabetical characters
const char* caesar_cipher(char* msg[], int k);
//general rotation shifting all characters k times
const char* general_rotation(char* msg[], int k);
//output data from file in hexadecimal format
const char* hex_conversion(char* msg[]);
//output data from the file in binary notation
const char* bin_conversion(char* msg[]);
#endif
