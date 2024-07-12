#include "../includes/s21_tests.h"

START_TEST(empty) {
  char str1[] = "";
  char str2 = '\0';

  ck_assert_pstr_eq(s21_strchr(str1, str2), strchr(str1, str2));
}
END_TEST

START_TEST(hello_) {
  char str1[] = "hello";
  char str2 = '\0';

  ck_assert_pstr_eq(s21_strchr(str1, str2), strchr(str1, str2));
}
END_TEST

START_TEST(_hello) {
  char str1[] = "";
  char str2 = 'h';

  ck_assert_pstr_eq(s21_strchr(str1, str2), strchr(str1, str2));
}
END_TEST

START_TEST(hello_world_o) {
  char str1[] = "Hello World";
  char str2 = 'o';

  ck_assert_pstr_eq(s21_strchr(str1, str2), strchr(str1, str2));
}
END_TEST

START_TEST(Hello_World_l) {
  char str1[] = "Hello World";
  char str2 = 'l';

  ck_assert_pstr_eq(s21_strchr(str1, str2), strchr(str1, str2));
}
END_TEST

START_TEST(Hello_World_p) {
  char str1[] = "Hello World peace";
  char str2 = 'p';

  ck_assert_pstr_eq(s21_strchr(str1, str2), strchr(str1, str2));
}
END_TEST

START_TEST(hidden_o) {
  char str1[] = "00000000O00000000";
  char str2 = 'O';

  ck_assert_pstr_eq(s21_strchr(str1, str2), strchr(str1, str2));
}
END_TEST

START_TEST(find_zero) {
  char str1[] = "1234506789";
  char str2 = '0';

  ck_assert_pstr_eq(s21_strchr(str1, str2), strchr(str1, str2));
}
END_TEST

Suite *suite_strchr(void) {
  Suite *s = suite_create("suite_strchr");
  TCase *tc = tcase_create("strchr_tc");

  tcase_add_test(tc, empty);
  tcase_add_test(tc, hello_);
  tcase_add_test(tc, _hello);
  tcase_add_test(tc, hello_world_o);
  tcase_add_test(tc, Hello_World_l);
  tcase_add_test(tc, Hello_World_p);
  tcase_add_test(tc, hidden_o);
  tcase_add_test(tc, find_zero);

  suite_add_tcase(s, tc);
  return s;
}