#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t count = 0;
  if (dest && src) {
    for (s21_size_t i = s21_strlen(dest); count < n; i++) {
      dest[i] = src[count];
      count++;
    }
  }
  return dest;
}