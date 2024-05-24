CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c11 -fsanitize=address -g
GCOVFLAGS = -fprofile-arcs -ftest-coverage

HEADER = s21_string.h
SRC = $(wildcard ./*.c)

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
	lcov -t "gcov_report" -o coverage_report.info  -c -d .
	genhtml -o ./report coverage_report.info
	rm -f *.gcda *.gcno *.info  *.gcov report.out
	open ./report/index-sort-f.html 

check: 
	clang-format -style=Google -n ./*/*.c

rebuild: clean all

clean:
	rm -f *.a *.o *.gcno *gcov *.info *.out
	rm -rf ./report