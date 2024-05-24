#ifndef SRS_TESTS_S21_TESTS_H_
#define SRS_TESTS_S21_TESTS_H_

#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../s21_string.h"

Suite *suite_strcat(void);

void run_tests(void);
void run_testcase(Suite *testcase);

#endif // SRS_TESTS_S21_TESTS_H_