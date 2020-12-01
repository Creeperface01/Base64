/***********************************************************
* Base64 library                                           *
* @author Ahmed Elzoughby                                  *
* @date July 23, 2017                                      *
* @url https://github.com/Creeperface01/Base64             *
* Purpose: encode and decode base64 format                 *
***********************************************************/

#ifndef BASE46_H
#define BASE46_H

#include <stdlib.h>
#include <memory.h>

#include <string.h>

char *base64_encode_str(char *plain);

/***********************************************
Encodes ASCCI string into base64 format string
@param plain ASCII string to be encoded
@return encoded base64 format string
***********************************************/
int base64_encode(char *plain, int length, char **destination);


char *base64_decode_str(char *cipher);

/***********************************************
decodes base64 format string into ASCCI string
@param plain encoded base64 format string
@return ASCII string to be encoded
***********************************************/
int base64_decode(char *cipher, int length, char **destination);


#endif //BASE46_H
