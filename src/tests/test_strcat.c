#include "../includes/s21_tests.h"

START_TEST(Hello_World) {
  char src[] = " World!!!";
  char res[5 + 10] = "Hello";
  char expected[5 + 10] = "Hello";

  s21_strcat(res, src);
  strcat(expected, src);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(empty_first) {
  char src[] = " World!!!";
  char res[0 + 10] = "";
  char expected[0 + 10] = "";

  s21_strcat(res, src);
  strcat(expected, src);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(empty_last) {
  char src[] = "";
  char res[] = "Hello";
  char expected[] = "Hello";

  s21_strcat(res, src);
  strcat(expected, src);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(check_register) {
  char src[6] = "WoRlD";
  char res[6 + 5] = "Hello";
  char expected[6 + 5] = "Hello";

  s21_strcat(res, src);
  strcat(expected, src);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(check_register_and_num) {
  char src[] = "W0r1d";
  char res[6 + 5] = "Hello";
  char expected[6 + 5] = "Hello";

  s21_strcat(res, src);
  strcat(expected, src);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(check_register_and_num_and_sim) {
  char src[8] = "W0rlD?!";
  char res[8 + 5] = "Hello";
  char expected[8 + 5] = "Hello";

  s21_strcat(res, src);
  strcat(expected, src);

  ck_assert_str_eq(res, expected);
}
END_TEST

Suite *suite_strcat(void) {
  Suite *s = suite_create("suite_strcat");
  TCase *tc = tcase_create("strcat_tc");

  tcase_add_test(tc, Hello_World);
  tcase_add_test(tc, empty_first);
  tcase_add_test(tc, empty_last);
  tcase_add_test(tc, check_register);
  tcase_add_test(tc, check_register_and_num);
  tcase_add_test(tc, check_register_and_num_and_sim);

  suite_add_tcase(s, tc);
  return s;
}