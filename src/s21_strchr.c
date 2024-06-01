#include "s21_string.h"

char *s21_strchr(const char *str, int c){
    char *result = S21_NULL;
    while((*str != '\0') && (*str != c)){
        str++;
    }
    if(*str == c){
        result = (char*)str;
    }
    return result;
}