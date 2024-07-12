#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  const char *last_sym = s21_NULL;

  while (*str) {
    if (*str == (char)c) {
      last_sym = str;
    }
    str++;
  }

  if (c == '\0') {
    return (char *)str;
  }

  return (char *)last_sym;
}