#include "s21_string.h"

char *s21_strtok(char *str, const char *delim){
    static char *saveptr;
    char *token;

    if (str ==  S21_NULL){
        str = saveptr;
    }

    str += s21_strspn(str, delim);

    if(*str == '\0'){
        saveptr = str;
        return S21_NULL;
    }

    token = str;
    str = s21_strpbrk(token, delim);
    if (str == S21_NULL){
        saveptr = s21_strchr(token, '\0');
    } else {
        *str = '\0';
        saveptr = str + 1;
    }

    return token;
}