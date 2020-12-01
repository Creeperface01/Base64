#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
#pragma ide diagnostic ignored "hicpp-signed-bitwise"
/***********************************************************
* Base64 library implementation                            *
* @author Ahmed Elzoughby                                  *
* @date July 23, 2017                                      *
***********************************************************/

#include "base64.h"


char base46_map[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                     'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                     'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                     'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'};

char *base64_encode_str(char *plain) {
    return base64_encode(plain, strlen(plain));
}


char *base64_encode(char *plain, int length) {
    char counts = 0;
    char buffer[3];
    char *cipher = malloc(strlen(plain) * 4 / 3 + 4);
    int i, c = 0;

    for (i = 0; i < length; i++) {
        buffer[counts++] = plain[i];
        if (counts == 3) {
            cipher[c++] = base46_map[buffer[0] >> 2];
            cipher[c++] = base46_map[((buffer[0] & 0x03) << 4) + (buffer[1] >> 4)];
            cipher[c++] = base46_map[((buffer[1] & 0x0f) << 2) + (buffer[2] >> 6)];
            cipher[c++] = base46_map[buffer[2] & 0x3f];
            counts = 0;
        }
    }

    if (counts > 0) {
        cipher[c++] = base46_map[buffer[0] >> 2];
        if (counts == 1) {
            cipher[c++] = base46_map[(buffer[0] & 0x03) << 4];
            cipher[c++] = '=';
        } else {                      // if counts == 2
            cipher[c++] = base46_map[((buffer[0] & 0x03) << 4) + (buffer[1] >> 4)];
            cipher[c++] = base46_map[(buffer[1] & 0x0f) << 2];
        }
        cipher[c++] = '=';
    }

    cipher[c] = '\0';
    return cipher;
}

char *base64_decode_str(char *cipher) {
    char *str;

    int length = base64_decode(cipher, &str);
    str[length] = '\0';

    return str;
}

int base64_decode(char *cipher, char **destination) {
    char counts = 0;
    char buffer[4];
    char *plain = malloc(strlen(cipher) * 3 / 4);
    *destination = plain;
    int i, p = 0;

    int length = strlen(cipher);
    for (i = 0; i < length; i++) {
        char k;
        for (k = 0; k < 64 && base46_map[k] != cipher[i]; k++);
        buffer[counts++] = k;
        if (counts == 4) {
            plain[p++] = (buffer[0] << 2) + (buffer[1] >> 4);
            if (buffer[2] != 64)
                plain[p++] = (buffer[1] << 4) + (buffer[2] >> 2);
            if (buffer[3] != 64)
                plain[p++] = (buffer[2] << 6) + buffer[3];
            counts = 0;
        }
    }

    return p;
}

#pragma clang diagnostic pop