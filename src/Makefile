CC=gcc

TARGET?=s21_string.a
TEST_TARGET?=test_s21_string.a
TEST_OUPTUT?=test
TEST_GCOV_OUTPUT?=test_gcov
COVERAGE_REPORT=./coverage
COVERAGE_INFO=coverage.info


SRC_DIR?=.
TEST_SRC_DIR?=./tests

OBJ_DIR?=./objects
TEST_OBJ_DIR?=./tests/objects

INC_DIR:=./
TEST_INC_DIR:=./includes

INC:=$(wildcard $(INC_DIR)*.h)
SRC:=$(wildcard $(SRC_DIR)/s21_*.c)
TEST_INC:=$(wildcard $(TEST_INC_DIR)*.h)
TEST_SRC:=$(wildcard $(TEST_SRC_DIR)/*.c)

objects:=$(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
GCOV_objects:=$(addprefix $(TEST_OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
TEST_objects:=$(addprefix $(TEST_OBJ_DIR)/, $(notdir $(TEST_SRC:.c=.o)))

GCDA=$(wildcard $(TEST_OBJ_DIR)/*.gcda)
GCNO=$(wildcard $(TEST_OBJ_DIR)/*.gcno)

AR:= ar rc
INDEX:= ranlib
RM:= rm -f
MK:=mkdir -p


CFLAGS=-c -Wall -Wextra -Werror -std=c11
TEST_GLAGS:= -g $(CFLAGS) 
GCOV_FLAGS?=-fprofile-arcs -ftest-coverage
TEST_LIBS?=$(shell pkg-config --cflags --libs check) -lm

RESET := \033[0m
GREEN := \033[0;32m
RED := \033[0;31m
YELLOW := \033[1;33m

all: test  s21_string.a gcov_report
	@echo "$(GREEN)All targets built successfully.$(RESET)"

gcov_obj: $(GCOV_OBJ)

$(TARGET): $(objects)
	$(AR) $(TARGET) $(objects)
	$(INDEX) $(TARGET)

$(TEST_TARGET): $(GCOV_objects) $(INC)
	$(AR) $(TEST_TARGET) $(GCOV_objects)
	$(INDEX) $(TEST_TARGET)

test: $(TARGET) $(TEST_OBJ_DIR)/main.o $(TEST_objects) $(TEST_INC)
	@echo "$(YELLOW)Running tests...$(RESET)"
	$(CC) $(TEST_objects) $(TEST_OBJ_DIR)/main.o $(GCOV_FLAGS) -o $(TEST_OUPTUT) $(TEST_LIBS) -L. $(TARGET)

test_gcov: $(TEST_TARGET) $(TEST_OBJ_DIR)/main.o $(TEST_objects) 
	 @echo "$(YELLOW)Running tests with coverage...$(RESET)"
	$(CC) $(TEST_objects) $(TEST_OBJ_DIR)/main.o $(GCOV_FLAGS) -o $(TEST_GCOV_OUTPUT) $(TEST_LIBS) -L. $(TEST_TARGET)
	@./$(TEST_OUTPUT) && echo "$(GREEN)Tests Passed$(RESET)" || echo "$(RED)Tests Failed$(RESET)"

$(TEST_OBJ_DIR)/main.o: main.c 
	@$(MK) $(TEST_OBJ_DIR)
	$(CC) $(CFLAGS) -o $(TEST_OBJ_DIR)/main.o main.c  


$(TEST_OBJ_DIR)%.o: $(TEST_SRC_DIR)%.c $(TEST_INC) 
	@$(MK) $(TEST_OBJ_DIR)
	$(CC) $(TEST_GLAGS) -o $@ -c $<


$(objects): $(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC) 
	@$(MK) $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<


$(GCOV_objects): $(TEST_OBJ_DIR)%.o: $(SRC_DIR)%.c $(TEST_INC)
	@$(MK) $(TEST_OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

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
	$(RM) $(objects)
	$(RM) $(GCDA)
	$(RM) $(GCNO)
	$(RM) $(TEST_objects)
	$(RM) $(GCOV_objects)
	$(RM) tests/objects/main.o

fclean: clean
	$(RM) $(TARGET)
	$(RM) $(TEST_TARGET)
	$(RM) $(TEST_OUPTUT)
	$(RM) $(TEST_GCOV_OUTPUT)
	$(RM) $(COVERAGE_INFO)
	$(RM) -r $(COVERAGE_REPORT)
	$(RM) tests/objects/main.o
re: fclean all
	@echo "$(GREEN)Rebuild complete.$(RESET)"

.PHONY: all clean fclean re open 