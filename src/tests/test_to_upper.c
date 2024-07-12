#include "../includes/s21_tests.h"

START_TEST(test_simple_uppercase) {
  char src[] = "hello";
  char expected[] = "HELLO";
  char *res = s21_to_upper(src);
  ck_assert_str_eq(res, expected);
  if (res) free(res);
}
END_TEST

START_TEST(test_mixed_case) {
  char src[] = "HelLo";
  char expected[] = "HELLO";
  char *res = s21_to_upper(src);
  ck_assert_str_eq(res, expected);
  if (res) free(res);
}
END_TEST

START_TEST(test_space) {
  char src[] = " ";
  char expected[] = " ";
  char *res = s21_to_upper(src);
  ck_assert_str_eq(res, expected);
  if (res) free(res);
}
END_TEST

START_TEST(test_null_input) {
  char src[] = "";
  char expected[] = "";
  char *res = s21_to_upper(src);
  ck_assert_str_eq(res, expected);
  if (res) free(res);
}
END_TEST

START_TEST(test_non_alphabetic) {
  char src[] = "Hello, World!";
  char expected[] = "HELLO, WORLD!";
  char *res = s21_to_upper(src);
  ck_assert_str_eq(res, expected);
  if (res) free(res);
}
END_TEST

Suite *suite_to_upper(void) {
  Suite *s = suite_create("suite_to_upper");
  TCase *tc = tcase_create("to_upper_tc");

  tcase_add_test(tc, test_simple_uppercase);
  tcase_add_test(tc, test_mixed_case);
  tcase_add_test(tc, test_space);
  tcase_add_test(tc, test_null_input);
  tcase_add_test(tc, test_non_alphabetic);

  suite_add_tcase(s, tc);
  return s;
}