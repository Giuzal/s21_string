#include "s21_string.h"

int main(){
    char *s = "Hello_World";
    char *up_s = s21_to_upper(s);
    printf("\nOriginal string: %s\nModified string: %s\n", s, up_s);

    
    return 0;
}