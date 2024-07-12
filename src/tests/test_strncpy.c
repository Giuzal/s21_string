#include "../includes/s21_tests.h"

START_TEST(empty) {
  char src[] = "";
  char res[] = "";
  char exp[] = "";
  s21_size_t n_byte = 0;

  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);

  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(no_byte) {
  char src[] = "012";
  char res[] = "012";
  char exp[] = "012";
  s21_size_t n_byte = 0;

  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);

  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(empty_src) {
  char src[] = "";
  char res[] = "012";
  char exp[] = "012";
  s21_size_t n_byte = 0;

  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);

  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(one_byte) {
  char src[] = "012";
  char res[5] = "012";
  char exp[5] = "012";
  s21_size_t n_byte = 1;

  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);

  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(two_bytes) {
  char src[] = "012";
  char res[7] = "012";
  char exp[7] = "012";
  s21_size_t n_byte = 2;

  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);

  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(string) {
  char src[] = "Str1ng";
  char res[7 + 7] = "Str1ng";
  char exp[7 + 7] = "Str1ng";
  s21_size_t n_byte = 7;

  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);

  ck_assert_str_eq(res, exp);
}
END_TEST

Suite *suite_strncpy(void) {
  Suite *s = suite_create("suite_strncpy");
  TCase *tc = tcase_create("strncpy_tc");

  tcase_add_test(tc, empty);
  tcase_add_test(tc, no_byte);
  tcase_add_test(tc, empty_src);
  tcase_add_test(tc, one_byte);
  tcase_add_test(tc, two_bytes);
  tcase_add_test(tc, string);

  suite_add_tcase(s, tc);
  return s;
}