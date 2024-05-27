#include "s21_string.h"

char *s21_strtok(char *string, const char *delim){
    static char *saveptr;
    char *token;

    if (string ==  S21_NULL){
        string = saveptr;
    }

    string += s21_strspn(string, delim);

    if(*string == '\0'){
        saveptr = string;
        return S21_NULL;
    }

    token = string;
    string = s21_strpbrk(token, delim);
    if (string == S21_NULL){
        saveptr = s21_strchr(token, '\0');
    } else {
        *string = '\0';
        saveptr = string + 1;
    }

    return token;
}