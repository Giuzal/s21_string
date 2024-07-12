#include "../includes/s21_tests.h"

START_TEST(insert_in_middle) {
  const char src[] = "hello world";
  const char str[] = "beautiful ";
  char *res = s21_insert(src, str, 6);
  const char expected[] = "hello beautiful world";

  ck_assert_str_eq(res, expected);
  free(res);
}
END_TEST

START_TEST(insert_at_start) {
  const char src[] = "world";
  const char str[] = "hello ";
  char *res = s21_insert(src, str, 0);
  const char expected[] = "hello world";

  ck_assert_str_eq(res, expected);
  free(res);
}
END_TEST

START_TEST(insert_at_end) {
  const char src[] = "hello";
  const char str[] = " world";
  char *res = s21_insert(src, str, 5);
  const char expected[] = "hello world";

  ck_assert_str_eq(res, expected);
  free(res);
}
END_TEST

START_TEST(insert_empty_str) {
  const char src[] = "hello";
  const char str[] = "";
  char *res = s21_insert(src, str, 3);
  const char expected[] = "hello";

  ck_assert_str_eq(res, expected);
  free(res);
}
END_TEST

START_TEST(insert_in_empty_src) {
  const char src[] = "";
  const char str[] = "hello";
  char *res = s21_insert(src, str, 0);
  const char expected[] = "hello";

  ck_assert_str_eq(res, expected);
  free(res);
}
END_TEST

START_TEST(insert_invalid_index) {
  const char src[] = "hello";
  const char str[] = "world";
  char *res = s21_insert(src, str, 10);
  ck_assert_ptr_eq(res, NULL);
}
END_TEST

Suite *suite_insert(void) {
  Suite *s = suite_create("suite_insert");
  TCase *tc = tcase_create("insert_tc");

  tcase_add_test(tc, insert_in_middle);
  tcase_add_test(tc, insert_at_start);
  tcase_add_test(tc, insert_at_end);
  tcase_add_test(tc, insert_empty_str);
  tcase_add_test(tc, insert_in_empty_src);
  tcase_add_test(tc, insert_invalid_index);

  suite_add_tcase(s, tc);
  return s;
}