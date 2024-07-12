
#include "s21_string.h"
void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (!src || !str) return s21_NULL;
  s21_size_t len_str = s21_strlen(str);
  s21_size_t len_src = s21_strlen(src);
  if (start_index > len_src) {
    return s21_NULL;
  }
  char *buffer = (char *)malloc((len_str + len_src + 1) * sizeof(char));
  s21_memcpy(buffer, src, start_index);
  s21_memcpy(buffer + start_index, str, len_str);
  s21_memcpy(buffer + start_index + len_str, src + start_index,
             len_src - start_index);
  buffer[len_str + len_src] = '\0';
  return buffer;
}