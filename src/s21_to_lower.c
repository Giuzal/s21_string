
#include "s21_string.h"

void *s21_to_lower(const char *str) {
  char *lower_str = s21_NULL;

  if (str != s21_NULL) {
    size_t lenght = s21_strlen(str);
    lower_str = (char *)malloc((lenght + 1) * sizeof(char));

    if (lower_str) {
      for (s21_size_t i = 0; i <= lenght; ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z')
          lower_str[i] = (str[i] - 'A') + 'a';
        else
          lower_str[i] = str[i];
      }
    }
    lower_str[lenght] = '\0';
  }

  return lower_str;
}