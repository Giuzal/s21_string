#include "s21_string.h"

size_t s21_strspn(const char *string, const char *charset) {
  const char *str1;
  const char *str2;
  s21_size_t count = 0;

  for (str1 = string; *str1 != '\0'; str1++) {
    s21_size_t is = 0;
    for (str2 = charset; *str2 != '\0'; str2++) {
      if (*str1 == *str2) {
        count++;
        is = 1;
        break;
      }
    }
    if (!is) break;
  }
  return count;
}