CC = gcc
CFLAGS = -Wall -Wextra -g --coverage
LDFLAGS = -lgcov -lcheck -lm -lpthread

MODULES_DIR = modules
TESTS_DIR = tests
BUILD_DIR = build
COVERAGE_DIR = coverage_report


MODULES_SRC = $(wildcard $(MODULES_DIR)/*.c)
MODULES_OBJ = $(MODULES_SRC:.c=.o)

TESTS_SRC = $(wildcard $(TESTS_DIR)/*.c)
TESTS_OBJ = $(TESTS_SRC:.c=.o)

all: s21_matrix.a $(BUILD_DIR)/test gcov_report

$(MODULES_DIR)/%.o: $(MODULES_DIR)/%.c s21_matrix.h
	$(CC) $(CFLAGS) -c $< -o $@


s21_matrix.a: $(MODULES_OBJ)
	ar rcs $@ $^


$(TESTS_DIR)/%.o: $(TESTS_DIR)/%.c s21_matrix.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/test: s21_matrix.a $(TESTS_OBJ)
	mkdir -p $(BUILD_DIR)
	$(CC) $(TESTS_OBJ) s21_matrix.a -o $@ $(LDFLAGS)

gcov_report: $(BUILD_DIR)/test
	./$(BUILD_DIR)/test
	mkdir -p $(COVERAGE_DIR)
	lcov --capture --directory . --output-file $(COVERAGE_DIR)/coverage.info --include "$(MODULES_DIR)/*.c"
	genhtml $(COVERAGE_DIR)/coverage.info --output-directory $(COVERAGE_DIR)
	open $(COVERAGE_DIR)/index.html

clean:
	rm -f $(MODULES_OBJ) $(TESTS_OBJ) $(BUILD_DIR)/test s21_matrix.a
	rm -rf $(COVERAGE_DIR)
	rm -f $(MODULES_DIR)/*.gcno $(MODULES_DIR)/*.gcda
	rm -rf $(BUILD_DIR)
	rm -rf $(TESTS_DIR)/*.gcno $(TESTS_DIR)/*.gcda

