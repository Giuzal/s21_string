#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *s = str;
  const unsigned char *res = s21_NULL;
  for (s21_size_t i = 0; i < n; i++) {
    if (s[i] == (unsigned char)c) {
      res = s + i;
      break;
    }
  }
  return (void *)res;
}