#include "s21_string.h"

char *s21_strcpy(char *dest, const char *src){
    if(dest == NULL) return NULL;

    char *return_dest = dest;

    while(*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';

    return return_dest;
}