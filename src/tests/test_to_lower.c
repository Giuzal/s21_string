#include "../includes/s21_tests.h"

START_TEST(test_simple_lowercase) {
  char src[] = "HELLO";
  char expected[] = "hello";
  char *res = s21_to_lower(src);
  ck_assert_str_eq(res, expected);
  if (res) free(res);
}
END_TEST

START_TEST(test_mixed_case) {
  char src[] = "HelLo";
  char expected[] = "hello";
  char *res = s21_to_lower(src);
  ck_assert_str_eq(res, expected);
  if (res) free(res);
}
END_TEST

START_TEST(test_space) {
  char src[] = " ";
  char expected[] = " ";
  char *res = s21_to_lower(src);
  ck_assert_str_eq(res, expected);
  if (res) free(res);
}
END_TEST

START_TEST(test_null_input) {
  char src[] = "";
  char expected[] = "";
  char *res = s21_to_lower(src);
  ck_assert_str_eq(res, expected);
  if (res) free(res);
}
END_TEST

START_TEST(test_non_alphabetic) {
  char src[] = "Hello, World!";
  char expected[] = "hello, world!";
  char *res = s21_to_lower(src);
  ck_assert_str_eq(res, expected);
  if (res) free(res);
}
END_TEST

Suite *suite_to_lower(void) {
  Suite *s = suite_create("suite_to_lower");
  TCase *tc = tcase_create("to_lower_tc");

  tcase_add_test(tc, test_simple_lowercase);
  tcase_add_test(tc, test_mixed_case);
  tcase_add_test(tc, test_space);
  tcase_add_test(tc, test_null_input);
  tcase_add_test(tc, test_non_alphabetic);

  suite_add_tcase(s, tc);
  return s;
}