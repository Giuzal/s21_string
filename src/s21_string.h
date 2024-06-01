#ifndef S21_STRING_H
#define S21_STRING_H
#include <stdio.h>
#include <stdlib.h>

#define S21_NULL ((void*)0)
typedef unsigned long s21_size_t;

size_t s21_strlen(const char *str);
size_t s21_strspn(const char *string, const char *charset);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, size_t n);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strchr(const char *str, int c);
char *s21_strtok(char *str, const char *delim);
//void *s21_to_upper(const char *str);
#endif // S21_STRING_H