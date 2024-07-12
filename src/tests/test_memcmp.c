#include "../includes/s21_tests.h"

START_TEST(Hello_World) {
  char test1[] = "hello";
  char test2[] = "world";
  int res = s21_memcmp(test1, test2, 5);
  int expected = memcmp(test1, test2, 5);

  ck_assert_int_eq(res, expected);
}
END_TEST

START_TEST(numbers) {
  char test1[] = "12345";
  char test2[] = "6789";
  int res = s21_memcmp(test1, test2, 5);
  int expected = memcmp(test1, test2, 5);

  ck_assert_int_eq(res, expected);
}
END_TEST

START_TEST(more) {
  char test1[] = "hello";
  char test2[] = "world";
  int res = s21_memcmp(test1, test2, 6);
  int expected = memcmp(test1, test2, 6);

  ck_assert_int_eq(res, expected);
}
END_TEST

START_TEST(check_register) {
  char test1[] = "hEllo";
  char test2[] = "woRld";
  int res = s21_memcmp(test1, test2, 3);
  int expected = memcmp(test1, test2, 3);

  ck_assert_int_eq(res, expected);
}
END_TEST

START_TEST(check_register_and_num) {
  char test1[] = "hE0llo";
  char test2[] = "woRl22d";
  int res = s21_memcmp(test1, test2, 5);
  int expected = memcmp(test1, test2, 5);

  ck_assert_int_eq(res, expected);
}
END_TEST

START_TEST(check_register_and_num_and_sim) {
  char test1[] = "hE0ll!!!o";
  char test2[] = "woRl22d";
  int res = s21_memcmp(test1, test2, 5);
  int expected = memcmp(test1, test2, 5);

  ck_assert_int_eq(res, expected);
}
END_TEST

Suite *suite_memcmp(void) {
  Suite *s = suite_create("suite_memcmp");
  TCase *tc = tcase_create("memcmp_tc");

  tcase_add_test(tc, Hello_World);
  tcase_add_test(tc, numbers);
  tcase_add_test(tc, more);
  tcase_add_test(tc, check_register);
  tcase_add_test(tc, check_register_and_num);
  tcase_add_test(tc, check_register_and_num_and_sim);

  suite_add_tcase(s, tc);
  return s;
}