#include "../includes/s21_tests.h"

START_TEST(zero) {
  int errnum = 0;
  char *res = s21_strerror(errnum);
  char *expected = strerror(errnum);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(large_error) {
  int errnum = 1000;
  char *res = s21_strerror(errnum);
  char *expected = strerror(errnum);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(negative_error) {
  int errnum = -1;
  char *res = s21_strerror(errnum);
  char *expected = strerror(errnum);

  ck_assert_str_eq(res, expected);
}
END_TEST

Suite *suite_strerror(void) {
  Suite *s = suite_create("suite_strerror");
  TCase *tc = tcase_create("strerror_tc");

  tcase_add_test(tc, zero);
  tcase_add_test(tc, large_error);
  tcase_add_test(tc, negative_error);

  suite_add_tcase(s, tc);
  return s;
}