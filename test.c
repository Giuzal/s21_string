#include "s21_string.h"

int main()
{
    char string1[100]= "hello";
    const char string2[] = "world";

    char* result = s21_strcat(string1, string2);

    printf("%s\n", result);

    return 0;
}

