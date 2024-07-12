#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t counter = 0;

  for (const char *a = str1; *a; a++) {
    unsigned short key = 0;
    for (const char *b = str2; *b; b++) {
      if (*a == *b) {
        key = 1;
        break;
      }
    }
    if (key) {
      break;
    } else {
      counter++;
    }
  }
  return counter;
}