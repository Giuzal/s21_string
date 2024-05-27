#include "s21_string.h"

char *s21_strchr(const char *string, int c){
    char *result = S21_NULL;
    while((*string != '\0') && (*string != c)){
        string++;
    }
    if(*string == c){
        result = (char*)string;
    }
    return result;
}