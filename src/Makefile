CC=gcc

TARGET?=s21_string.a
TEST_TARGET?=test_s21_string.a
TEST_OUTPUT?=test
TEST_GCOV_OUTPUT?=test_gcov
COVERAGE_REPORT=./coverage
COVERAGE_INFO=coverage.info

SRC_DIR?=.
TEST_SRC_DIR?=./tests

OBJ_DIR?=./objects
TEST_OBJ_DIR?=./tests/objects

INC_DIR:=./
TEST_INC_DIR:=./includes

INC:=$(shell find $(INC_DIR) -name "*.h")
SRC:=$(shell find $(SRC_DIR) -name "s21_*.c")

TEST_INC:=$(shell find $(TEST_INC_DIR) -name "*.h")
TEST_SRC:=$(shell find $(TEST_SRC_DIR) -name "*.c")

OBJS:=$(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
GCOV_OBJS:=$(addprefix $(TEST_OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
TEST_OBJS:=$(addprefix $(TEST_OBJ_DIR)/, $(notdir $(TEST_SRC:.c=.o)))

MAIN_OBJ:=$(OBJ_DIR)/main.o

GCDA=$(shell find $(TEST_OBJ_DIR) -name "*.gcda")
GCNO=$(shell find $(TEST_OBJ_DIR) -name "*.gcno")

AR:= ar rc
INDEX:= ranlib
RM:= rm -f
MK:=mkdir -p

GFLAGS=-c -Wall -Wextra -Werror -std=c11
CFLAGS?= $(GFLAGS)
TEST_FLAGS:= -g $(GFLAGS) 
GCOV_FLAGS?=-fprofile-arcs -ftest-coverage
TST_LIBS?=$(shell pkg-config --cflags --libs check) -lm

RESET := \033[0m
GREEN := \033[0;32m
RED := \033[0;31m
YELLOW := \033[1;33m

all: $(TARGET) test gcov_report
	@echo "$(GREEN)All targets built successfully.$(RESET)"

$(TARGET): $(OBJS)
	$(AR) $(TARGET) $(OBJS)
	$(INDEX) $(TARGET)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC)
	@$(MK) $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

$(TEST_OBJ_DIR)/%.o: $(TEST_SRC_DIR)/%.c $(TEST_INC)
	@$(MK) $(TEST_OBJ_DIR)
	$(CC) $(TEST_FLAGS) -o $@ -c $<

$(MAIN_OBJ): $(SRC_DIR)/main.c $(INC)
	@$(MK) $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

test: $(TARGET) $(MAIN_OBJ) $(TEST_OBJS) $(TEST_INC) 
	@echo "$(YELLOW)Running tests...$(RESET)"
	$(CC) $(TEST_OBJS) $(MAIN_OBJ) $(GCOV_FLAGS) -o $(TEST_OUTPUT) $(TST_LIBS) -L. $(TARGET)
	@./$(TEST_OUTPUT) && echo "$(GREEN)Tests Passed$(RESET)" || echo "$(RED)Tests Failed$(RESET)"

gcov_report: $(COVERAGE_REPORT)
	@echo "$(YELLOW)Generating coverage report...$(RESET)"
	genhtml $(COVERAGE_INFO) -o $(COVERAGE_REPORT)
	@echo "$(GREEN)Coverage report generated successfully.$(RESET)"

$(COVERAGE_REPORT): CFLAGS += $(GCOV_FLAGS)
$(COVERAGE_REPORT): $(COVERAGE_INFO)
	genhtml $(COVERAGE_INFO) -o $(COVERAGE_REPORT)

$(COVERAGE_INFO): test_gcov
	@echo "$(YELLOW)Generating coverage data...$(RESET)"
	./$(TEST_GCOV_OUTPUT)
	geninfo $(TEST_OBJ_DIR) -b . -o ./$(COVERAGE_INFO)
	@echo "$(GREEN)Coverage data generated successfully.$(RESET)"

open:
	open coverage/src/index.html

clean:
	@echo "$(YELLOW)Cleaning up...$(RESET)"
	$(RM) $(OBJS)
	$(RM) $(GCDA)
	$(RM) $(GCNO)
	$(RM) $(TEST_OBJS)
	$(RM) $(GCOV_OBJS)
	$(RM) $(MAIN_OBJ)

fclean: clean
	@echo "$(YELLOW)Performing full clean...$(RESET)"
	$(RM) $(TARGET)
	$(RM) $(TEST_TARGET)
	$(RM) $(TEST_OUTPUT)
	$(RM) $(TEST_GCOV_OUTPUT)
	$(RM) $(COVERAGE_INFO)
	$(RM) -r $(COVERAGE_REPORT)

re: fclean all
	Z@echo "$(GREEN)Rebuild complete.$(RESET)"

.PHONY: all clean fclean re open