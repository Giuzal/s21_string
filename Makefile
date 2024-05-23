CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c11 -fsanitize=address -g
GCOVFLAGS = -fprofile-arcs -ftest-coverage

HEADER = s21_string.h
SRC = $(wildard ./*.c)

OBJ_LIBRARY := $(patsubst %.c, %.o, $(SRC))

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: s21_string.a gcov_report test

s21_string.a: $(OBJ_LIBRARY) $(HEADER)
	ar rcs s21_string.a $(OBJ_LIBRARY)
	ranlib s21_string.a
	rm -rf ./*.o 

test: s21_string.a tests/test.c
	$(CC) $(CFLAGS) tests/test.c s21_string.a -o test.out -lm -lcheck
	./test.out

gcov_report: s21_string.a tests/test.c
	$(CC) $(CFLAGS) tests/test.c $(SRC) -o report.out -lm -lcheck ./report.out
	gcov -f $(SRC)