#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int res = 0;
  for (; *str1 && (*str1 == *str2) && n > 0; n--, str1++, str2++)
    ;
  if (n > 0) {
    res = *(unsigned char *)str1 - *(unsigned char *)str2;
  }
  return res;
}
