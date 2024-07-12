#include "../includes/s21_tests.h"

START_TEST(empty) {
  char str1[] = "";
  char str2[] = "";

  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(hello_) {
  char str1[] = "hello";
  char str2[] = "";

  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(_hello) {
  char str1[] = "";
  char str2[] = "hello";

  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(hello_world_o) {
  char str1[] = "Hello World";
  char str2[] = "o";

  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(hello_world_l) {
  char str1[] = "Hello World";
  char str2[] = "l";

  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(hello_world_e) {
  char str1[] = "Hello World";
  char str2[] = "e";

  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(just_e) {
  char str1[] = "eeeeeeeeE";
  char str2[] = "e";

  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(find_E) {
  char str1[] = "eeeeeeeeE";
  char str2[] = "\0";

  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

Suite *suite_strpbrk(void) {
  Suite *s = suite_create("suite_strpbrk");
  TCase *tc = tcase_create("strpbrk_tc");

  tcase_add_test(tc, empty);
  tcase_add_test(tc, hello_);
  tcase_add_test(tc, _hello);
  tcase_add_test(tc, hello_world_o);
  tcase_add_test(tc, hello_world_l);
  tcase_add_test(tc, hello_world_e);
  tcase_add_test(tc, just_e);
  tcase_add_test(tc, find_E);

  suite_add_tcase(s, tc);
  return s;
}