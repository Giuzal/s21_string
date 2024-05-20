#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, size_t n){
    if (dest == NULL || src == NULL || n == 0){
        return dest;
    }

    s21_size_t i = 0;

    while(i < n && src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }

    while (i < n) {
        dest[i] = '\0';
        i++;
    }

    return dest;
}