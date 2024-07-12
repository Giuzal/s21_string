#include "s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *s = str;
  unsigned char ch = (unsigned char)c;
  s21_size_t i;
  for (i = 0; i < n; i++) {
    s[i] = ch;
  }
  s[i] = '\0';
  return str;
}
