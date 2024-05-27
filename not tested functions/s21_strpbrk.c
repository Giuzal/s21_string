#include "s21_string.h"

char *s21_strpbrk(const char *string, const char *charset){
    while(*string != '\0')
    {
        const char *temp = charset;
        while (*temp != '\0'){
            if (*string == *temp){
                return (char *) string;
            }
            temp++;
        }
        string++;
    }

    return S21_NULL;
}