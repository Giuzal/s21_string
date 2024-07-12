#include "../includes/s21_tests.h"

START_TEST(trim_empty_string) {
  const char *src = "";
  const char *trim_chars = " ";
  void *res = s21_trim(src, trim_chars);
  char *expected = "";
  ck_assert_str_eq(res, expected);
  free(res);
}
END_TEST

START_TEST(trim_no_trim_chars) {
  const char *src = "Hello, World!";
  const char *trim_chars = "";
  void *res = s21_trim(src, trim_chars);
  char *expected = "Hello, World!";
  ck_assert_str_eq(res, expected);
  free(res);
}
END_TEST

START_TEST(trim_no_trim_needed) {
  const char *src = "Hello, World!";
  const char *trim_chars = "#";
  void *res = s21_trim(src, trim_chars);
  char *expected = "Hello, World!";
  ck_assert_str_eq(res, expected);
  free(res);
}
END_TEST

START_TEST(trim_all_trim_chars) {
  const char *src = "   ";
  const char *trim_chars = " ";
  void *res = s21_trim(src, trim_chars);
  char *expected = "";
  ck_assert_str_eq(res, expected);
  free(res);
}
END_TEST

START_TEST(trim_only_trim_chars) {
  const char *src = "#####";
  const char *trim_chars = "#";
  void *res = s21_trim(src, trim_chars);
  char *expected = "";
  ck_assert_str_eq(res, expected);
  free(res);
}
END_TEST

Suite *suite_trim(void) {
  Suite *s = suite_create("suite_trim");
  TCase *tc = tcase_create("trim_tc");

  tcase_add_test(tc, trim_empty_string);
  tcase_add_test(tc, trim_no_trim_chars);
  tcase_add_test(tc, trim_no_trim_needed);
  tcase_add_test(tc, trim_all_trim_chars);
  tcase_add_test(tc, trim_only_trim_chars);

  suite_add_tcase(s, tc);
  return s;
}