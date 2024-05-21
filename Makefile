NAME=s21_string

CC = gcc
GFLAGS = -Wall -Wextra -Werror -std=c11
SRCS = $(wildcard s21_*.c)
HEADER = $(s21_string.h)


OBJS=$(SRCS: .c=.o)

EXIT_PATH=./

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(EXIT_PATH)$@

clean:
	rm -rf $(OBJS)

re:
	make clean
	make

	.PHONY: $(NAME) all clean re


