
#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *upper_str = s21_NULL;

  if (str != s21_NULL) {
    size_t lenght = s21_strlen(str);
    upper_str = (char *)malloc((lenght + 1) * sizeof(char));

    if (upper_str) {
      for (s21_size_t i = 0; i <= lenght; ++i) {
        if (str[i] >= 'a' && str[i] <= 'z')
          upper_str[i] = (str[i] - 'a') + 'A';
        else
          upper_str[i] = str[i];
      }
    }
    upper_str[lenght] = '\0';
  }

  return upper_str;
}