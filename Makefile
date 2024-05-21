NAME=s21_string

CC = gcc
GFLAGS = -Wall -Wextra -Werror -std=c11
SRCS = $(wildcard s21_*.c)
HEADER = $(s21_string.h)

EXIT_PATH=./

#OBJS=$(SRCS: .c=.o)

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(GFLAGS) $(SRCS) -o $(EXIT_PATH)$@

clean:
	rm -rf $(NAME)

re:
	make clean
	make

	.PHONY: all clean re


