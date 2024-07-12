#include "../includes/s21_tests.h"

START_TEST(hello_world) {
  char src[] = " world!!!";
  char res[5 + 15] = "hello ";
  char expected[5 + 15] = "hello ";

  s21_strcpy(res, src);
  strcpy(expected, src);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(_world) {
  char src[] = "world!!!";
  char res[5 + 15] = "";
  char expected[5 + 15] = "";

  s21_strcpy(res, src);
  strcpy(expected, src);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(hello_) {
  char src[] = "";
  char res[5 + 15] = "hellos";
  char expected[5 + 15] = "hellos";

  s21_strcpy(res, src);
  strcpy(expected, src);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(empty) {
  char src[] = "";
  char res[5 + 15] = "";
  char expected[5 + 15] = "";

  s21_strcpy(res, src);
  strcpy(expected, src);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(empty_num) {
  char src[] = "1";
  char res[5 + 15] = "";
  char expected[5 + 15] = "";

  s21_strcpy(res, src);
  strcpy(expected, src);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(hello) {
  char src[] = " my dear friend\"";
  char res[5 + 25] = "Hello";
  char expected[5 + 25] = "Hello";

  s21_strcpy(res, src);
  strcpy(expected, src);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(over_string) {
  char src[] = "hel\0lo";
  char res[10 + 10] = "Wor\0ld";
  char expected[10 + 10] = "Wor\0ld";

  s21_strcpy(res, src);
  strcpy(expected, src);

  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(hard_test) {
  char src[] = "1234567890qwerty?!!";
  char res[50 + 50] = "1234567890qwerty?![]0QWERTY";
  char expected[50 + 50] = "1234567890qwerty?![]0QWERTY";

  s21_strcpy(res, src);
  strcpy(expected, src);

  ck_assert_str_eq(res, expected);
}
END_TEST

Suite *suite_strcpy(void) {
  Suite *s = suite_create("suite_strcpy");
  TCase *tc = tcase_create("strcpy_tc");

  tcase_add_test(tc, hello_world);
  tcase_add_test(tc, _world);
  tcase_add_test(tc, hello_);
  tcase_add_test(tc, empty);
  tcase_add_test(tc, empty_num);
  tcase_add_test(tc, hard_test);
  tcase_add_test(tc, hello);
  tcase_add_test(tc, over_string);

  suite_add_tcase(s, tc);
  return s;
}