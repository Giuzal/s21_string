#ifndef S21_STRING_H
#define S21_STRING_H

typedef unsigned long s21_size_t;

#include <stdio.h>
#include <stdlib.h>

s21_size_t s21_strlen(const char *str);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, size_t n);
char *s21_strbrk(char *dest, const char *src);
char *s21_strpbrk(char *dest, const char *src, size_t n);
char *s21_strtok(char *dest, const char *src);

#endif // S21_STRING_H