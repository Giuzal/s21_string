#include "../includes/s21_tests.h"

START_TEST(find_last_sym) {
  char test1[6] = "hello";
  void *res = s21_memchr(test1, 'o', 5);
  void *expected = memchr(test1, 'o', 5);

  ck_assert_ptr_eq(res, expected);
}
END_TEST

START_TEST(find_first_sym) {
  char test1[6] = "hello";
  void *res = s21_memchr(test1, 'h', 5);
  void *expected = memchr(test1, 'h', 5);

  ck_assert_ptr_eq(res, expected);
}
END_TEST

START_TEST(find_no_sym) {
  char test1[6] = "hello";
  void *res = s21_memchr(test1, 'x', 5);
  void *expected = memchr(test1, 'x', 5);

  ck_assert_ptr_eq(res, expected);
}
END_TEST

START_TEST(check_register) {
  char test1[6] = "hellO";
  void *res = s21_memchr(test1, 'o', 4);
  void *expected = memchr(test1, 'o', 4);

  ck_assert_ptr_eq(res, expected);
}
END_TEST

START_TEST(check_register_and_num) {
  char src[10] = "W0r1d";
  void *res = s21_memchr(src, '1', 4);
  void *expected = memchr(src, '1', 4);

  ck_assert_ptr_eq(res, expected);
}
END_TEST

START_TEST(check_register_and_num_and_sim) {
  char src[10] = "W0rlD?!";
  void *res = s21_memchr(src, '!', 4);
  void *expected = memchr(src, '!', 4);

  ck_assert_ptr_eq(res, expected);
}
END_TEST

Suite *suite_memchr(void) {
  Suite *s = suite_create("suite_memchr");
  TCase *tc = tcase_create("memchr_tc");

  tcase_add_test(tc, find_last_sym);
  tcase_add_test(tc, find_first_sym);
  tcase_add_test(tc, find_no_sym);
  tcase_add_test(tc, check_register);
  tcase_add_test(tc, check_register_and_num);
  tcase_add_test(tc, check_register_and_num_and_sim);

  suite_add_tcase(s, tc);
  return s;
}