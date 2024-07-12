#include "s21_string.h"

size_t s21_strlen(const char *str) {
  s21_size_t length = 0;
  if (str) {
    while (str[length] != '\0') {
      length++;
    }
  }
  return length;
}
