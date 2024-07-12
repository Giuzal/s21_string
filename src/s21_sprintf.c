#include "s21_string.h"

int s21_sprintf(char* str, const char* format, ...) {
  if (s21_NULL == str || s21_NULL == format) return 1;
  s21_memset(str, 0, s21_strlen(str));
  va_list args;
  va_start(args, format);
  int res = 0;
  s21_size_t index = 0;
  s21_size_t format_idx = 0;
  int error_code = 0;
  specifier_flags flags = {0, 0, 0, 0, 0};
  specifier params = {0, flags, 0, 0, 0, 0};
  char* specifier_string = s21_NULL;
  while (format[format_idx] != '\0' && error_code == 0) {
    reset_params(&params);
    if (format[format_idx] != '%') {
      str[index] = format[format_idx];
      index++;
      if (format_idx + 1 <= s21_strlen(format)) format_idx++;
    } else {
      if (format_idx + 1 <= s21_strlen(format)) format_idx++;
      specifier_string = specifier_reader(format, &params, &args, &format_idx,
                                          &error_code, index);
      if (specifier_string != s21_NULL && str != s21_NULL &&
          params.type != 'n') {
        s21_strcat(str, specifier_string);
        index += s21_strlen(specifier_string);
      }
      if (s21_NULL != specifier_string) free(specifier_string);
    }
  }
  if (error_code) {
    fprintf(stderr, "Invalid format of specifier\n");
    if (str != s21_NULL) free(str);
    va_end(args);
    return 1;
  }
  va_end(args);
  str[index] = '\0';
  res = s21_strlen(str);
  return res;
}

char* specifier_reader(const char* format, specifier* params, va_list* args,
                       s21_size_t* format_idx, int* error_code, int str_len) {
  char* string = calloc(2048, sizeof(char));
  if (!string) {
    *error_code = 1;
    return s21_NULL;
  }
  read_flags(format, format_idx, params, error_code);
  params->width = read_width(format, format_idx, args);
  params->precision = read_precision(format, format_idx, args, params);
  params->length = read_length(format, format_idx);
  params->type = read_type(format, format_idx, error_code);
  if (*error_code) {
    if (s21_NULL != string) free(string);
    return s21_NULL;
  }
  apply_params(params, args, string, str_len);
  return string;
}

void apply_params(specifier* params, va_list* args, char* string, int index) {
  char* buff = s21_NULL;
  char* hex_chars = {0};
  int* ptr;
  switch (params->type) {
    case 'c':
      buff = calloc(2048, sizeof(char));
      if (s21_NULL != buff) buff[0] = va_arg(*args, int);
      break;
    case 'd':
      if (params->length == 'l') {
        buff = long_int_to_string(va_arg(*args, long long int));
      } else if (params->length == 'h') {
        buff = short_int_to_string(va_arg(*args, int));
      } else {
        buff = int_to_string(va_arg(*args, int));
      }
      break;
    case 'i':
      if (params->length == 'l') {
        buff = long_int_to_string(va_arg(*args, long long int));
      } else if (params->length == 'h') {
        buff = short_int_to_string(va_arg(*args, int));
      } else {
        buff = int_to_string(va_arg(*args, int));
      }
      break;
    case 'e':
    case 'E':
      if (params->length == 'L') {
        buff = long_e_to_string(params, va_arg(*args, long double));
      } else {
        buff = e_to_string(params, va_arg(*args, double));
      }
      break;
    case 'f':
      if (!params->is_prec) params->precision = 6;
      if (params->length == 'L') {
        buff = long_float_to_string(params, va_arg(*args, long double));
      } else {
        buff = float_to_string(params, va_arg(*args, double));
      }
      break;
    case 'g':
    case 'G':

      if (params->length == 'L') {
        buff = long_g_to_string(params, va_arg(*args, long double));
      } else {
        buff = g_to_string(params, va_arg(*args, double));
      }
      break;
    case 'o':
      if (params->length == 'h') {
        buff = short_octal_to_str(va_arg(*args, int));
      } else if (params->length == 'l') {
        buff = long_octal_to_str(va_arg(*args, long long int));
      } else {
        buff = octal_to_str(va_arg(*args, long int));
      }
      break;
    case 's':
      buff = calloc(2048, sizeof(char));
      if (buff != s21_NULL) {
        if (params->precision != 0)
          s21_strncpy(buff, va_arg(*args, char*), params->precision);
        else
          s21_strcpy(buff, va_arg(*args, char*));
      }
      break;
    case 'u':
      if (params->length == 'h') {
        buff = short_unsigned_to_string(
            (short unsigned int)va_arg(*args, unsigned int));
      } else {
        buff = unsigned_to_string(va_arg(*args, long int));
      }
      break;
    case 'x':
    case 'X':
      if (params->type == 'x') {
        hex_chars = "0123456789abcdef";
      } else if (params->type == 'X') {
        hex_chars = "0123456789ABCDEF";
      }
      if (params->length == 'l') {
        buff = long_hex_to_str(va_arg(*args, long long int), hex_chars);
      } else if (params->length == 'h') {
        buff = short_hex_to_str(va_arg(*args, long long int), hex_chars);
      } else {
        buff = hex_to_str(va_arg(*args, unsigned long int), hex_chars);
      }
      break;
    case 'p':
      hex_chars = "0123456789abcdef";
      buff = ptr_to_str(va_arg(*args, void*), hex_chars);
      break;
    case 'n':
      ptr = (int*)va_arg(*args, int*);
      *ptr = index;
      break;
    case '%':
      buff = calloc(2048, sizeof(char));
      if (s21_NULL != buff) buff[0] = '%';
      break;
  }
  if (params->type == 'n') return;
  if (buff) {
    if (params->type != 'g' && params->type != 'G')
      apply_precision(params, buff);
    if (params->width != 0) {
      int len1 = s21_strlen(buff);
      buff = apply_width(params, buff, len1);
    }

    apply_flags(params, buff);
    s21_strcat(string, buff);
    if (s21_NULL != buff) free(buff);
  }
}

int read_width(const char* format, s21_size_t* index, va_list* args) {
  int res = 0;
  char* string = calloc(2048, sizeof(char));
  if (s21_NULL == string) {
    return 0;
  }
  int idx = 0;
  if (format[*index] == '*') {
    res = va_arg(*args, int);
    if (*index + 1 <= s21_strlen(format)) *index = *index + 1;
  } else {
    while (format[*index] < 58 && format[*index] > 47) {
      string[idx] = format[*index];
      idx++;
      if (*index + 1 <= s21_strlen(format)) *index = *index + 1;
    }
    res = string_to_int(string);
  }
  if (s21_NULL != string) free(string);
  return res;
}

char read_length(const char* format, s21_size_t* index) {
  char res = 0;
  if (is_length(format[*index])) {
    res = format[*index];
    if (*index + 1 <= s21_strlen(format)) *index = *index + 1;
  }
  return res;
}

int read_precision(const char* format, s21_size_t* index, va_list* args,
                   specifier* params) {
  int res = 0;
  int idx = 0;
  if (format[*index] == '.') {
    *index = *index + 1;
    if (format[*index] == '*') {
      res = va_arg(*args, int);
      if (*index + 1 <= s21_strlen(format)) *index = *index + 1;
    } else if (format[*index] < 58 && format[*index] > 47) {
      while (format[*index] < 58 && format[*index] > 47) {
        if (idx != 0) res *= 10;
        res += format[*index] - 48;
        idx++;
        if (*index + 1 <= s21_strlen(format)) *index = *index + 1;
      }
    } else
      res = 0;
    params->is_prec = 1;
  }
  return res;
}

// Обработать ошибку
void read_flags(const char* format, s21_size_t* index, specifier* params,
                int* error_code) {
  // char res = 0;
  while (is_flag(format[*index])) {
    switch (format[*index]) {
      case '+':
        params->flags.plus_flag += 1;
        break;
      case '-':
        params->flags.minus_flag += 1;
        break;
      case '#':
        params->flags.hash_flag += 1;
        break;
      case '0':
        params->flags.zero_flag += 1;
        break;
      case ' ':
        params->flags.space_flag += 1;
        break;
    }
    if (*index + 1 <= s21_strlen(format)) *index = *index + 1;
  }
  if (params->flags.hash_flag > 1 || params->flags.minus_flag > 1 ||
      params->flags.plus_flag > 1 || params->flags.space_flag > 1 ||
      params->flags.zero_flag > 1)
    *error_code = 1;
  if (params->flags.minus_flag) params->flags.zero_flag = 0;
  if (params->flags.plus_flag) params->flags.space_flag = 0;
  // return res;
}

char read_type(const char* format, s21_size_t* index, int* error_code) {
  char res = 0;
  for (int i = 0; i < specifier_amount; i++) {
    if (format[*index] == specifiers_list[i]) {
      res = specifiers_list[i];
      if (*index + 1 <= s21_strlen(format)) *index = *index + 1;
      break;
    }
  }
  if (res == 0) *error_code = 1;
  return res;
}

int string_to_int(char* string) {
  int index = 0;
  int res = 0;
  while (*string < 58 && *string > 47) {
    if (index != 0) res *= 10;
    res += *string - 48;
    string++;
    index++;
  }
  return res;
}

char* int_to_string(int arg) {
  char* str = calloc(2048, sizeof(char));
  if (arg == 0) return str;
  int sign_flag = 0;
  int start_idx = 0;
  if (arg < 0) {
    sign_flag = 1;
  }
  int len = floor(log10(abs(arg)));
  if (sign_flag) {
    str[0] = '-';
    len++;
    start_idx++;
  }
  str[len + 1] = '\0';
  while (len >= start_idx || arg != 0) {
    str[len] = llabs(arg % 10) + '0';
    arg = arg / 10;
    len--;
  }
  return str;
}

char* long_int_to_string(long long int arg) {
  char* str = calloc(2048, sizeof(char));
  if (arg == 0) return str;
  int sign_flag = 0;
  int start_idx = 0;
  if (arg < 0) {
    sign_flag = 1;
  }
  int len = floor(log10(llabs(arg)));
  if (sign_flag) {
    str[0] = '-';
    len++;
    start_idx++;
  }
  str[len + 1] = '\0';
  while (len >= start_idx || arg != 0) {
    str[len] = llabs(arg % 10) + '0';
    arg = arg / 10;
    len--;
  }
  return str;
}

char* short_int_to_string(int arg) {
  char* str = calloc(2048, sizeof(char));
  if (arg == 0) return str;
  int sign_flag = 0;
  int start_idx = 0;
  int low_limit = -32768;
  int high_limit = 32767;

  if (arg > high_limit) {
    arg = abs(low_limit + (arg % high_limit) - 1);
    sign_flag = 1;
    start_idx++;
  } else if (arg < 0) {
    sign_flag = 1;
    if (arg < low_limit) {
      arg = abs(high_limit + (arg % low_limit) + 1);
      sign_flag = 0;
    } else {
      arg = abs(arg);
    }
  }
  short int len = floor(log10(abs(arg)));
  if (sign_flag) {
    str[0] = '-';
    len++;
    start_idx++;
  }
  str[len + 1] = '\0';
  while (len >= start_idx || arg != 0) {
    str[len] = (arg % 10) + '0';
    arg = arg / 10;
    len--;
  }
  return str;
}

char* unsigned_to_string(long int arg) {
  char* str = calloc(2048, sizeof(char));
  int start_idx = 0;
  long int limit = 4294967295;
  if (arg < 0) {
    if (arg < limit * -1) {
      arg = (arg % limit) + 1;
    }
    arg += limit + 1;
  }
  if (arg > limit) {
    arg %= limit + 1;
  }
  if (arg == 0) {
    str[0] = '0';
  } else {
    int len = floor(log10(labs(arg)));
    str[len + 1] = '\0';
    while (len >= start_idx || arg != 0) {
      str[len] = labs(arg % 10) + '0';
      arg = arg / 10;
      len--;
    }
  }
  return str;
}

char* short_unsigned_to_string(unsigned int arg) {
  char* str = calloc(2048, sizeof(char));
  int start_idx = 0;
  short unsigned int limit = 65535;
  if (arg > limit) {
    arg %= limit;
  }
  if (arg == 0) {
    str[0] = '0';
  } else {
    int len = floor(log10(arg));
    str[len + 1] = '\0';
    while (len >= start_idx || arg != 0) {
      str[len] = arg % 10 + '0';
      arg = arg / 10;
      len--;
    }
  }
  return str;
}

char* ptr_to_str(void* num, char* hex_chars) {
  char* str = s21_NULL;
  str = (char*)calloc(2048, sizeof(char));
  unsigned long* hex_num = (unsigned long*)num;
  unsigned long value = (unsigned long)hex_num;
  s21_strcat(str, "0x");
  if (value == 0) {
    s21_strcat(str, "0");
    str[3] = '\0';
  } else {
    unsigned long temp = value;
    int index = get_hex_length(&value) + 1;
    str[index + 1] = '\0';
    while (temp >= 16 && index >= 0) {
      str[index] = hex_chars[temp % 16];
      temp /= 16;
      index--;
    }
    if (temp > 0 && index >= 0) {
      str[index] = hex_chars[temp];
    }
  }
  return str;
}

char* hex_to_str(unsigned long int num, char* hex_chars) {
  char* str = calloc(2048, sizeof(char));
  unsigned long int limit = 4294967295;
  if (num > limit) {
    num %= limit + 1;
  }
  if (num == 0) {
    s21_strcat(str, "0");
    str[3] = '\0';
  } else {
    int index = get_hex_length(&num);
    str[index] = '\0';
    index--;
    while (num != 0) {
      str[index] = hex_chars[num % 16];
      num /= 16;
      index--;
    }
  }
  return str;
}

int get_hex_length(void* num) {
  long long int value = *(long long int*)num;
  int counter = 0;
  while (value != 0) {
    value = (int)value / 16;
    counter++;
  }
  return counter;
}

char* short_hex_to_str(long long int num, char* hex_chars) {
  char* str = calloc(2048, sizeof(char));
  int limit = 65535;
  if (num < 0) {
    if (num < limit * -1) {
      num = (num % limit) + 1;
    }
    num += limit + 1;
  }
  if (num > limit) {
    num %= limit + 1;
  }
  if (num == 0) {
    s21_strcat(str, "0");
    str[0] = '\0';
  } else {
    s21_size_t index = get_hex_length(&num);
    str[index] = '\0';
    while (num != 0) {
      str[--index] = hex_chars[num % 16];
      num /= 16;
    }
  }
  return str;
}

char* long_hex_to_str(long long int num, char* hex_chars) {
  char* str = calloc(2048, sizeof(char));
  int parse_flag = 0;
  if (num < 0) {
    if (num < -2147483647) {
      parse_flag = 1;
    }
    num = llabs(num);
  }
  if (num == 0) {
    s21_strcat(str, "0");
    str[0] = '\0';
  } else {
    int index = get_hex_length(&num);
    if (parse_flag == 1) {
      int diff = 15 - index;
      while (diff >= 0) {
        str[diff] = hex_chars[15];
        diff--;
      }
      diff = 15 - index;
      index = 16;
      str[index] = '\0';
      int addition = 1;
      char hex_char = 0;
      while (index > diff + 1) {
        int hex_index = 15 - (num % 16) + addition;
        if (hex_index == 16) hex_char = '0';
        if (hex_index < 16) hex_char = hex_chars[15 - (num % 16) + addition];
        str[--index] = hex_char;
        if (hex_char == '0') {
          addition = 1;
        } else {
          addition = 0;
        }
        num /= 16;
      }
    } else {
      str[index] = '\0';
      while (num != 0) {
        str[--index] = hex_chars[num % 16];
        num /= 16;
      }
    }
  }
  return str;
}

char* octal_to_str(long int num) {
  char* str = calloc(2048, sizeof(char));
  long int limit = 4294967295;
  if (num > limit) {
    num %= limit;
    num--;
  }
  char* octal_chars = "01234567";
  if (num == 0) {
    s21_strcat(str, "0");
    str[2] = '\0';
  } else {
    unsigned int temp = num;
    s21_size_t index = get_octal_len(temp) - 1;
    str[index + 1] = '\0';
    while (temp != 0) {
      str[index] = octal_chars[temp % 8];
      temp /= 8;
      index--;
    }
  }
  return str;
}

char* long_octal_to_str(long long int num) {
  char* str = calloc(2048, sizeof(char));
  char* octal_chars = "01234567";
  if (num == 0) {
    s21_strcat(str, "0");
    str[2] = '\0';
  } else {
    long long int temp = num;
    s21_size_t index = get_octal_len(temp) - 1;
    str[index + 1] = '\0';
    while (temp != 0) {
      str[index] = octal_chars[temp % 8];
      temp /= 8;
      index--;
    }
  }
  return str;
}

char* short_octal_to_str(short int num) {
  char* str = calloc(2048, sizeof(char));
  unsigned short int limit = 65535;
  if (num > limit) {
    num %= limit;
  }
  char* octal_chars = "01234567";
  if (num == 0) {
    s21_strcat(str, "0");
    str[2] = '\0';
  } else {
    unsigned short int temp = num;
    s21_size_t index = get_octal_len(temp) - 1;
    str[index + 1] = '\0';
    while (temp != 0) {
      str[index] = octal_chars[temp % 8];
      temp /= 8;
      index--;
    }
  }
  return str;
}

s21_size_t get_octal_len(long long int value) {
  s21_size_t res = 0;
  while (value != 0) {
    value /= 8;
    res++;
  }
  return res;
}

char* e_to_string(specifier* params, double num) {
  char* str;
  int len = (int)floor(log10(fabs(num)));
  num *= pow(10, (-1 * len));
  str = float_to_string(params, num);
  int diff = 0;
  s21_size_t str_len = s21_strlen(str);
  if ((str_len < 8 && str[0] != '-') || (str_len < 9 && str[0] == '-')) {
    if (str[0] != '-') {
      diff = 8 - str_len;
    } else
      diff = 9 - str_len;
    if ((int)str_len < params->precision) {
      diff = params->precision - str_len;
      for (int i = 0; i < diff; ++i) {
        str[str_len] = '0';
        str_len++;
      }
    }
  }
  if (params->type == 'e' || params->type == 'g' || params->type == 'G') {
    str[str_len] = 'e';
  } else if (params->type == 'E') {
    str[str_len] = 'E';
  }
  str_len++;
  if (len < 0) {
    str[str_len] = '-';
  } else {
    str[str_len] = '+';
  }
  str_len++;
  if (len < 10) {
    str[str_len] = '0';
    str[str_len + 1] = 48 + abs(len);
    str_len += 2;
  } else {
    char* len_buff = int_to_string(len);
    s21_strcat(str, len_buff);
    str_len += s21_strlen(len_buff);
    if (s21_NULL != len_buff) free(len_buff);
  }

  str[str_len] = '\0';

  return str;
}

int char_to_int(char arg) {
  int res = 0 + arg;
  return res;
}

int is_flag(char letter) {
  return letter == '#' || letter == '-' || letter == '+' || letter == ' ' ||
         letter == '0';
}

int is_length(char letter) {
  return letter == 'l' || letter == 'h' || letter == 'L';
}

void reset_params(specifier* params) {
  params->type = 0;
  params->flags.hash_flag = 0;
  params->flags.plus_flag = 0;
  params->flags.minus_flag = 0;
  params->flags.zero_flag = 0;
  params->flags.space_flag = 0;
  params->width = 0;
  params->precision = 0;
  params->is_prec = 0;
  params->length = 0;
}

char* apply_width(specifier* params, char* buff, int len) {
  int diff = 0;
  char width[512] = {0};
  int width_index = 0;
  char* string = calloc(2048, sizeof(char));
  if (params->width > len) {
    diff = params->width - len;
    for (int i = 0; i < diff; ++i) {
      if (params->flags.zero_flag && params->type != 'c' &&
          params->type != 's') {
        width[width_index] = '0';
      } else
        width[width_index] = ' ';
      width_index++;
    }
  }
  if (!params->flags.minus_flag) {
    s21_strcat(string, width);
    s21_strcat(string, buff);
  } else {
    s21_strcat(string, buff);
    s21_strcat(string, width);
  }
  if (s21_NULL != buff) free(buff);
  return string;
}

void apply_precision(specifier* params, char* string) {
  int is_num = is_num_specificator(params->type);
  if (!is_num) {
    return;
  }
  int counter = 0;
  int read_flag = 0;
  char* buff = calloc(2048, sizeof(char));
  s21_size_t string_len = s21_strlen(string);
  if (is_dec(params->type)) {
    s21_size_t index = 0;
    if (string[0] == '-') {
      buff[0] = '-';
      index++;
      string_len--;
    };
    if (params->precision > (int)string_len) {
      for (s21_size_t i = 0; i < params->precision - string_len; ++i) {
        buff[index] = '0';
        index++;
      }
    }
    if (string[0] == '-')
      s21_strcat(buff, string + 1);
    else
      s21_strcat(buff, string);
    s21_strcpy(string, buff);
  } else {
    for (s21_size_t i = 0; i < string_len; i++) {
      if (read_flag) counter++;
      if (string[i] == '.') read_flag = 1;
    }
    while (counter < params->precision) {
      string[string_len] = '0';
      counter++;
      string_len++;
    }
    string[string_len] = '\0';
  }
  if (s21_NULL != buff) free(buff);
}

void apply_flags(specifier* params, char* string) {
  if (params->flags.plus_flag) apply_plus(string);
  if (params->flags.space_flag) apply_space(string);
  if (params->flags.hash_flag) apply_hash(string, params);
}

void apply_hash(char* buff, specifier* params) {
  char* znach = calloc(2048, sizeof(char));
  if (params->type == 'o' || params->type == 'x' || params->type == 'X') {
    znach[0] = '0';
    if (params->type == 'x') {
      znach[1] = 'x';
    } else if (params->type == 'X') {
      znach[1] = 'X';
    }
    s21_strcat(znach, buff);
    s21_strncpy(buff, znach, s21_strlen(znach) + 1);
  } else if (params->type == 'e' || params->type == 'E' ||
             params->type == 'f' || params->type == 'g' ||
             params->type == 'G') {
    if (s21_strchr(buff, '.') == s21_NULL) {
      s21_strcat(buff, ".");
    }
  }
  if (s21_NULL != znach) free(znach);
}

void apply_plus(char* string) {
  char* temp = s21_NULL;
  temp = calloc(2048, sizeof(char));
  if (temp) {
    if (string[0] != '-') {
      temp[0] = '+';
      s21_strcpy(temp + 1, string);
      s21_strcpy(string, temp);
    }
    if (s21_NULL != temp) free(temp);
  }
}

void apply_space(char* string) {
  char* temp = s21_NULL;
  temp = calloc(2048, sizeof(char));
  if (temp) {
    if (string[0] != '-') {
      temp[0] = ' ';
      s21_strcpy(temp + 1, string);
      s21_strcpy(string, temp);
    }
    if (s21_NULL != temp) free(temp);
  }
}

char* long_e_to_string(specifier* params, long double arg) {
  char* str;
  long int len = (int)floor(log10l(fabsl(arg)));
  if (params->precision == 0) {
    params->precision = 1;
  }
  arg *= powl(10, (-1 * len));
  str = long_float_to_string(params, arg);
  int diff = 0;
  int str_len = s21_strlen(str);
  if ((str_len < 8 && str[0] != '-') || (str_len < 9 && str[0] == '-')) {
    if (str[0] != '-') {
      diff = 8 - str_len;
    } else {
      diff = 9 - str_len;
    }
    for (int i = 0; i < diff; ++i) {
      str[str_len] = '0';
      str_len++;
    }
  }
  if (str[0] == 'i' || str[0] == '-') {
    return str;
  }
  if (params->type == 'e' || params->type == 'E') {
    if (params->type == 'e') {
      str[str_len] = 'e';
    } else {
      str[str_len] = 'E';
    }
    str_len++;
    if (len < 0) {
      str[str_len] = '-';
    } else {
      str[str_len] = '+';
    }
    str_len++;
    if (len < 10) {
      str[str_len] = '0';
      str[str_len + 1] = 48 + labs(len);
      str_len += 2;
    } else {
      char* len_buff = int_to_string(len);
      s21_strcat(str, len_buff);
      str_len += s21_strlen(len_buff);
      if (s21_NULL != len_buff) free(len_buff);
    }
    str[str_len] = '\0';
  }
  return str;
}

char* long_float_to_string(specifier* params, long double arg) {
  char* str = s21_NULL;
  if (params->precision == 0) {
    str = long_int_to_string((long long)roundl(arg));
    return str;
  }
  str = calloc(2048, sizeof(char));
  int index = 0;
  if (arg < 0) {
    str[0] = '-';
    arg *= -1;
    index++;
  }
  long long int dec = (long long int)arg + 0.5;
  long double dummy;
  long double fract = modfl(arg, &dummy);

  long int len = (int)floor(log10l(arg));
  if (index != 0) len++;
  for (int i = len; i >= index; --i) {
    str[i] = (char)((dec % 10) + 48);
    dec /= 10;
  }
  str[++len] = '.';
  int temp_len = len + params->precision;
  dec = (long long int)(roundl(fract * pow(10, params->precision)));
  for (int i = temp_len; i > len; --i) {
    str[i] = (char)((dec % 10) + 48);
    dec /= 10;
  }
  str[++temp_len] = '\0';
  return str;
}

char* float_to_string(specifier* params, double arg) {
  char* str = s21_NULL;
  if (params->precision == 0) {
    str = int_to_string((int)round(arg));
    return str;
  }
  str = calloc(2048, sizeof(char));
  int index = 0;
  if (arg < 0) {
    str[0] = '-';
    arg *= -1;
    index++;
  }
  int dec = (int)arg;
  double dummy;
  double fract = modf(arg, &dummy);
  int len = floor(log10(dec));
  if (index != 0) len++;
  for (int i = len; i >= index; --i) {
    str[i] = (char)((dec % 10) + 48);
    dec /= 10;
  }
  str[++len] = '.';
  int temp_len = len + params->precision;
  dec = (int)(round(fract * pow(10, params->precision)));
  for (int i = temp_len; i > len; --i) {
    str[i] = (char)((dec % 10) + 48);
    dec /= 10;
  }
  str[++temp_len] = '\0';
  return str;
}

char* g_to_string(specifier* params, double arg) {
  char* str;
  int dec = (int)arg;
  int len = floor(log10(dec)) + 1;
  if (len > params->precision) {
    params->precision = params->precision - 1;
    str = e_to_string(params, arg);
  } else if (len < params->precision) {
    params->precision = params->precision - len;
    str = float_to_string(params, arg);
  } else {
    str = int_to_string((int)round(arg));
  }
  return str;
}

char* long_g_to_string(specifier* params, long double arg) {
  char* str;
  long long int dec = (long long int)arg;
  int len = floor(log10(dec)) + 1;
  if (len > params->precision) {
    str = long_e_to_string(params, arg);
  } else if (len < params->precision) {
    params->precision = params->precision - len;
    str = long_float_to_string(params, arg);
  } else {
    str = long_int_to_string((int)round(arg));
  }
  return str;
}

int is_num_specificator(char type) {
  return type != 's' && type != 'p' && type != 'n' && type != 'c' &&
         type != '%';
}

int is_dec(char type) {
  return type == 'd' || type == 'i' || type == 'u' || type == 'x' ||
         type == 'X' || type == 'e' || type == 'E' || type == 'o' ||
         type == 'n';
}