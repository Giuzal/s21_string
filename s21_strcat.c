#include "s21_string.h"

char *strcat(char *dest, const char *src){

char *dest_string = dest;

while (*dest_string != '\0'){
    *dest_string++;
}

while (*src != '\0'){
    *dest_string++ = *src++;
}

*dest_string = '\0';

printf("%c", dest_string);

return dest;
}