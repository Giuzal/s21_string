#include "../includes/s21_tests.h"

START_TEST(Hello_world) {
  char a[] = "Helloworld";
  char b[] = "Helloworld";

  int got = s21_strcmp(a, b);
  int expected = strcmp(a, b);

  if (got > 1) got = 1;
  if (expected > 1) expected = 1;

  if (got < -1) got = -1;
  if (expected < -1) expected = -1;

  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(Hello_world_1) {
  char a[] = "Helloworld";
  char b[] = "Helloworld";

  int got = s21_strcmp(a, b);
  int expected = strcmp(a, b);

  if (got > 1) got = 1;
  if (expected > 1) expected = 1;

  if (got < -1) got = -1;
  if (expected < -1) expected = -1;

  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(Hell0_w0rld) {
  char a[] = "Hell0w0rld";
  char b[] = "Hel0w0rld";

  int got = s21_strcmp(a, b);
  int expected = strcmp(a, b);

  if (got > 1) got = 1;
  if (expected > 1) expected = 1;

  if (got < -1) got = -1;
  if (expected < -1) expected = -1;

  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(Helloworld_) {
  char a[] = "Helloworld";
  char b[] = "";

  int got = s21_strcmp(a, b);
  int expected = strcmp(a, b);

  if (got > 1) got = 1;
  if (expected > 1) expected = 1;

  if (got < -1) got = -1;
  if (expected < -1) expected = -1;

  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(_Helloworld) {
  char a[] = "";
  char b[] = "Helloworld";

  int got = s21_strcmp(a, b);
  int expected = strcmp(a, b);

  if (got > 1) got = 1;
  if (expected > 1) expected = 1;

  if (got < -1) got = -1;
  if (expected < -1) expected = -1;

  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(Helloworld_2) {
  char a[] = "L(8)L";
  char b[] = "L(8)L";

  int got = s21_strcmp(a, b);
  int expected = strcmp(a, b);

  if (got > 1) got = 1;
  if (expected > 1) expected = 1;

  if (got < -1) got = -1;
  if (expected < -1) expected = -1;

  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(empty) {
  char a[] = "";
  char b[] = "";

  int got = s21_strcmp(a, b);
  int expected = strcmp(a, b);

  if (got > 1) got = 1;
  if (expected > 1) expected = 1;

  if (got < -1) got = -1;
  if (expected < -1) expected = -1;

  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(only_num) {
  char a[] = "1234567890";
  char b[] = "1234567890";

  int got = s21_strcmp(a, b);
  int expected = strcmp(a, b);

  if (got > 1) got = 1;
  if (expected > 1) expected = 1;

  if (got < -1) got = -1;
  if (expected < -1) expected = -1;

  ck_assert_int_eq(got, expected);
}
END_TEST

Suite *suite_strcmp(void) {
  Suite *s = suite_create("suite_strcmp");
  TCase *tc = tcase_create("strcmp_tc");

  tcase_add_test(tc, Hello_world);
  tcase_add_test(tc, Hello_world_1);
  tcase_add_test(tc, Hell0_w0rld);
  tcase_add_test(tc, Helloworld_);
  tcase_add_test(tc, _Helloworld);
  tcase_add_test(tc, Helloworld_2);
  tcase_add_test(tc, empty);
  tcase_add_test(tc, only_num);

  suite_add_tcase(s, tc);
  return s;
}