#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  int len_src = s21_strlen(src);
  int len_trim_chars = s21_strlen(trim_chars);
  char *buffer = (char *)malloc((len_src + 1) * sizeof(char));
  int j = 0;
  for (int i = 0; i < len_src; i++) {
    if (s21_memchr(trim_chars, src[i], len_trim_chars) == s21_NULL) {
      buffer[j] = src[i];
      j++;
    }
  }
  buffer[j] = '\0';
  return buffer;
}