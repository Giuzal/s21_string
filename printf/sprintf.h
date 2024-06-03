#ifndef SPRINT_F_H
#define SPRINT_F_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

typedef struct {
    char type;
    char flag;
    int width;
    int precision;
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

#define specifiers_list (char const [specifier_amount]) {\
    'c', 'd', 'i', 'e', 'E', 'f', 'g', 'G', 'o', 's', 'u', 'x', 'X', 'p', 'n', '%'\
}

int s21_sprintf(char *str, const char *format, ...);

char* specifier_reader(const char *format, specifier* params, va_list *arg, int* format_idx);

char read_type(const char *format, int* index);
char read_flags(const char *format, int* index);
int read_width(const char *format, int* index);
int read_precision(const char *format, int* index);
char read_length(const char *format, int* index);

char* apply_params(specifier *params, va_list *args, char* string, int index);
void apply_width(specifier* params, char* string);

void int_to_string(char* buff, int arg);
void float_to_string(char* buff, float arg);
int string_to_int(char* string);
void hex_to_str(char* buff, void* num);
void octal_to_str(char* buff, void* num);
size_t get_octal_len(int value);

void reset_params(specifier* params);
int is_flag(char letter);
int is_length(char letter);

#endif