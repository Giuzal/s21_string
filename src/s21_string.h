#ifndef S21_STRING_H
#define S21_STRING_H

#include <ctype.h>
#include <float.h>
#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define s21_NULL ((void*)0)

typedef unsigned long s21_size_t;

s21_size_t s21_strlen(const char* str);
s21_size_t s21_strspn(const char* string, const char* charset);
s21_size_t s21_strcspn(const char* str1, const char* str2);
char* s21_strcat(char* dest, const char* src);
char* s21_strncat(char* dest, const char* src, s21_size_t n);
char* s21_strcpy(char* dest, const char* src);
char* s21_strncpy(char* dest, const char* src, s21_size_t n);
char* s21_strpbrk(const char* str1, const char* str2);
char* s21_strchr(const char* str, int c);
char* s21_strtok(char* str, const char* delim);
void* s21_to_upper(const char* str);
void* s21_to_lower(const char* str);
void* s21_insert(const char* src, const char* str, s21_size_t start_index);
void* s21_memchr(const void* str, int c, s21_size_t n);
char* s21_strtok(char* str, const char* delim);
char* s21_strstr(const char* haystack, const char* needle);
char* s21_strrchr(const char* str, int c);
char* s21_strerror(int errnum);
void s21_errnum_tostring(char* str, int num);  //???
void* s21_trim(const char* src, const char* trim_chars);
int s21_memcmp(const void* str1, const void* str2, s21_size_t n);
void* s21_memcpy(void* dest, const void* src, s21_size_t n);
void* s21_memset(void* str, int c, s21_size_t n);
int s21_strncmp(const char* str1, const char* str2, s21_size_t n);
int s21_strcmp(const char* str1, const char* str2);

// s21_sprintf

typedef struct {
  int minus_flag;
  int plus_flag;
  int hash_flag;
  int space_flag;
  int zero_flag;
} specifier_flags;

typedef struct {
  char type;
  specifier_flags flags;
  int width;
  int precision;
  int is_prec;
  char length;
} specifier;

typedef struct {
  char c;
  char d;
  char i;
  char e;
  char E;
  char f;
  char g;
  char G;
  char o;
  char s;
  char u;
  char x;
  char X;
  char p;
  char n;
  char percent;
} specifiers;

#define specifier_amount 16

#define specifiers_list                                                        \
  (char const[specifier_amount]) {                                             \
    'c', 'd', 'i', 'e', 'E', 'f', 'g', 'G', 'o', 's', 'u', 'x', 'X', 'p', 'n', \
        '%'                                                                    \
  }

int s21_sprintf(char* str, const char* format, ...);

char* specifier_reader(const char* format, specifier* params, va_list* args,
                       size_t* format_idx, int* error_code, int str_len);

char read_type(const char* format, size_t* index, int* error_code);
void read_flags(const char* format, size_t* index, specifier* params,
                int* error_code);
int read_width(const char* format, size_t* index, va_list* args);
int read_precision(const char* format, size_t* index, va_list* va_list,
                   specifier* params);
char read_length(const char* format, size_t* index);

void apply_params(specifier* params, va_list* args, char* string, int index);
char* apply_width(specifier* params, char* buff, int len);
void apply_precision(specifier* params, char* string);

int string_to_int(char* string);

char* int_to_string(int arg);
char* long_int_to_string(long long int arg);
char* short_int_to_string(int arg);

char* unsigned_to_string(long int arg);
char* short_unsigned_to_string(unsigned int arg);

char* ptr_to_str(void* num, char* hex_chars);
char* hex_to_str(unsigned long int num, char* hex_chars);
char* long_hex_to_str(long long int num, char* hex_chars);
char* short_hex_to_str(long long int num, char* hex_chars);
int get_hex_length(void* num);

char* octal_to_str(long int num);
char* short_octal_to_str(short int num);
char* long_octal_to_str(long long int num);
size_t get_octal_len(long long int value);

char* e_to_string(specifier* params, double num);

void reset_params(specifier* params);
int is_flag(char letter);
int is_length(char letter);

char* float_to_string(specifier* params, double arg);
char* long_float_to_string(specifier* params, long double arg);

char* long_e_to_string(specifier* params, long double arg);
char* g_to_string(specifier* params, double arg);
char* long_g_to_string(specifier* params, long double arg);

void apply_flags(specifier* params, char* string);
void apply_plus(char* string);
void apply_space(char* string);
void apply_hash(char* buff, specifier* params);

int is_num_specificator(char type);
int is_dec(char type);

#endif